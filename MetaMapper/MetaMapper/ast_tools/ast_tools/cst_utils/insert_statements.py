# Copyright (c) Facebook, Inc. and its affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#
# pyre-strict
from dataclasses import dataclass
from typing import List, Optional, Sequence, Set, Union

import libcst as cst
from libcst.codemod._context import CodemodContext
from libcst.codemod._visitor import ContextAwareTransformer


@dataclass
class StatementContext:
    # List of statements to insert before the current statement
    before_stmts: List[cst.BaseStatement]

    # List of statements to insert after the current statement
    after_stmts: List[cst.BaseStatement]

    keep_comments: bool


@dataclass
class BlockContext:
    # Ordered list of all statements accumulated into the new block body
    new_body: List[cst.BaseStatement]

    # Set of all inserted statements (through insert_* methods)
    added_stmts: Set[cst.BaseStatement]

    hanging_lines: List[cst.EmptyLine]


@dataclass
class InsertStatementsVisitorContext:
    """
    Context for the InsertStatementsVisitor about which statements
    have been requested to insert before/after the current one.
    """

    # Stack of contexts for statements
    ctx_stmt: List[StatementContext]

    # Stack of contexts for blocks
    ctx_block: List[BlockContext]


class RemoveEmptyBlocks(cst.CSTTransformer):
    def leave_SimpleStatementLine(self, original_node, updated_node):
        final_node = super().leave_SimpleStatementLine(original_node,
                                                       updated_node)
        if len(final_node.body) == 0:
            return cst.RemoveFromParent()
        return final_node

    def leave_If(self, original_node, updated_node):
        final_node = super().leave_If(original_node, updated_node)
        if not isinstance(final_node, cst.RemovalSentinel):
            if (final_node.orelse is not None
                    and len(final_node.orelse.body.body) == 0):
                final_node = final_node.with_changes(orelse=None)

            if len(final_node.body.body) == 0:
                return cst.RemoveFromParent()

        return final_node

    def leave_For(self, original_node, updated_node):
        final_node = super().leave_For(original_node, updated_node)
        if not isinstance(final_node, cst.RemovalSentinel):
            if len(final_node.body.body) == 0:
                return cst.RemoveFromParent()
        return final_node


class InsertStatementsVisitor(ContextAwareTransformer, RemoveEmptyBlocks):
    """
    Allows transformers to insert multiple statements before and after the currently-visited statement.

    This class is a mixin for :class:`~libcst.codemod.ContextAwareTransformer`. Subclasses gain the methods :meth:`~libcst.codemod.visitors.InsertStatementsVisitor.insert_statements_before_current` and :meth:`~libcst.codemod.visitors.InsertStatementsVisitor.insert_statements_after_current`. For example, you can create a pass that inserts print statements before each use of a variable::

      from libcst.metadata.visitors import InsertStatementsVisitor
      from libcst.metadata import ExpressionContextProvider, ExpressionContext
      class InsertPrintVisitor(InsertStatementsVisitor):
          METADATA_DEPENDENCIES = (ExpressionContextProvider,)

          def __init__(self, context: CodemodContext, name: str) -> None:
              super().__init__(context)
              self.name = name

          def visit_Name(self, node: cst.Name) -> None:
              if (
                  node.value == self.name
                  and self.get_metadata(ExpressionContextProvider, node)
                  == ExpressionContext.LOAD
              ):
                  self.insert_statements_before_current(
                      [cst.parse_statement(f"print({self.name})")]
                  )

    After initializing this visitor with ``name = "y"``, it will take this code::

        y = 1
        x = y

    And transform it into this code::

        y = 1
        print(y)
        x = y

    You **must** call ``super()`` methods if you override any visit or leave method for: Module, IndentedBlock, SimpleStatementLine, If, Try, FunctionDef, ClassDef, With, For, While.
    """

    CONTEXT_KEY = "InsertStatementsVisitor"

    def __init__(self, context: CodemodContext) -> None:
        super().__init__(context)
        self.context.scratch[InsertStatementsVisitor.
                             CONTEXT_KEY] = InsertStatementsVisitorContext([],
                                                                           [])

    def _context(self) -> InsertStatementsVisitorContext:
        return self.context.scratch[InsertStatementsVisitor.CONTEXT_KEY]

    def insert_statements_before_current(self, stmts: List[cst.BaseStatement]
                                         ) -> None:
        """
        Inserts a list of statements before the currently visited statement.

        While traversing the AST, the InsertStatementVisitor collects a stack of visited statements. For example, in the snippet::

            if y:
              x = 1

        When visiting ``y`` in ``visit_Name``, the current statement is the ``if``. When visiting ``1`` in ``visit_Integer``, the current statement is the ``x = 1`` assignment. Calling ``insert_statments_before_current`` will add a list of statements to be inserted before ``current``, which is handled in :meth:`~libcst.codemod.visitors.InsertStatementsVisitor.leave_Module` and :meth:`~libcst.codemod.visitors.InsertStatementsVisitor.leave_IndentedBlock`.
        """

        ctx = self._context()
        assert (
            len(ctx.ctx_block) > 0
        ), "InsertStatementVisitor is inserting a statement before having entered a statement"
        ctx.ctx_stmt[-1].before_stmts.extend(stmts)

    def insert_statements_after_current(self,
                                        stmts: List[cst.BaseStatement]) -> None:
        """
        Inserts a list of statements after the currently visited statement.

        See :meth:`~libcst.codemod.visitors.InsertStatementVisitor.insert_statements_before_current` for details.
        """

        ctx = self._context()
        assert (
            len(ctx.ctx_block) > 0
        ), "InsertStatementVisitor is inserting a statement before having entered a statement"
        ctx.ctx_stmt[-1].after_stmts.extend(stmts)

    def dont_keep_comments(self) -> None:
        ctx = self._context()
        ctx.ctx_stmt[-1].keep_comments = False

    def reattach_comments(self, original_node, new_node):
        if isinstance(new_node, list):
            if len(new_node) == 0:
                return new_node
            first_node = new_node[0]
            return [
                first_node.with_changes(
                    leading_lines=list(original_node.leading_lines) +
                    list(first_node.leading_lines))
            ] + new_node[1:]
        else:
            return new_node.with_changes(
                leading_lines=list(original_node.leading_lines) +
                list(new_node.leading_lines))

    def _visit_block(self) -> None:
        ctx = self._context()
        ctx.ctx_block.append(
            BlockContext(new_body=[], added_stmts=set(), hanging_lines=[]))

    def visit_IndentedBlock(self, node: cst.IndentedBlock) -> Optional[bool]:
        self._visit_block()
        return super().visit_IndentedBlock(node)

    def _leave_block(self, updated_body: Sequence[cst.BaseStatement]
                     ) -> List[cst.BaseStatement]:
        ctx = self._context()
        ctx_block = ctx.ctx_block.pop()
        return [
            stmt for stmt in ctx_block.new_body
            if stmt in updated_body or stmt in ctx_block.added_stmts
        ]

    def leave_IndentedBlock(self, original_node: cst.IndentedBlock,
                            updated_node: cst.IndentedBlock) -> cst.BaseSuite:
        final_node = super().leave_IndentedBlock(original_node, updated_node)
        if isinstance(final_node, cst.IndentedBlock):
            new_body = self._leave_block(final_node.body)
            return final_node.with_changes(body=new_body)
        else:
            self._context().ctx_block.pop()
            return final_node

        return final_node

    def visit_Module(self, node: cst.Module) -> Optional[bool]:
        self._visit_block()
        return super().visit_Module(node)

    def leave_Module(self, original_node: cst.Module,
                     updated_node: cst.Module) -> cst.Module:
        final_node = super().leave_Module(original_node, updated_node)
        new_body = self._leave_block(final_node.body)
        return final_node.with_changes(body=new_body)

    def _visit_stmt(self, node: cst.BaseStatement) -> None:
        ctx = self._context()
        ctx.ctx_stmt.append(
            StatementContext(before_stmts=[],
                             after_stmts=[],
                             keep_comments=True))

    def _add_hanging_lines(self, node: cst.BaseStatement,
                           ctx: BlockContext) -> cst.BaseStatement:
        if len(ctx.hanging_lines) > 0 and hasattr(node, 'leading_lines'):
            new_node = node.with_changes(leading_lines=ctx.hanging_lines +
                                         list(node.leading_lines))
            ctx.hanging_lines.clear()
            return new_node
        return node

    def _leave_stmt(
            self,
            original_node: cst.BaseStatement,
            final_node: Union[cst.BaseStatement, cst.RemovalSentinel],
    ) -> None:
        ctx = self._context()
        ctx_stmt = ctx.ctx_stmt.pop()
        if not ctx.ctx_block:
            return final_node

        ctx_block = ctx.ctx_block[-1]

        should_insert = not isinstance(final_node, cst.RemovalSentinel)
        if hasattr(original_node, 'leading_lines') and ctx_stmt.keep_comments:
            ctx_block.hanging_lines.extend(original_node.leading_lines)

            if should_insert:
                final_node = final_node.with_changes(leading_lines=[])

        if len(ctx_stmt.before_stmts) > 0:
            before_stmts = [
                self._add_hanging_lines(ctx_stmt.before_stmts[0], ctx_block)
            ] + ctx_stmt.before_stmts[1:]
            ctx_block.new_body.extend(before_stmts)
            ctx_block.added_stmts.update(set(before_stmts))

        if should_insert:
            final_node = self._add_hanging_lines(final_node, ctx_block)
            ctx_block.new_body.append(final_node)

        if len(ctx_stmt.after_stmts) > 0:
            ctx_block.new_body.extend(ctx_stmt.after_stmts)
            ctx_block.added_stmts.update(set(ctx_stmt.after_stmts))

        return final_node

    def visit_SimpleStatementLine(self, node: cst.SimpleStatementLine
                                  ) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_SimpleStatementLine(node)

    def leave_SimpleStatementLine(
            self,
            original_node: cst.SimpleStatementLine,
            updated_node: cst.SimpleStatementLine,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_SimpleStatementLine(original_node,
                                                       updated_node)
        return self._leave_stmt(original_node, final_node)

    def visit_If(self, node: cst.If) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_If(node)

    def leave_If(
            self,
            original_node: cst.If,
            updated_node: cst.If,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_If(original_node, updated_node)
        return self._leave_stmt(original_node, final_node)

    def visit_Try(self, node: cst.Try) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_Try(node)

    def leave_Try(
            self,
            original_node: cst.Try,
            updated_node: cst.Try,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_Try(original_node, updated_node)
        return self._leave_stmt(original_node, final_node)

    def visit_FunctionDef(self, node: cst.FunctionDef) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_FunctionDef(node)

    def leave_FunctionDef(
            self,
            original_node: cst.FunctionDef,
            updated_node: cst.FunctionDef,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_FunctionDef(original_node, updated_node)
        return self._leave_stmt(original_node, final_node)

    def visit_ClassDef(self, node: cst.ClassDef) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_ClassDef(node)

    def leave_ClassDef(
            self,
            original_node: cst.ClassDef,
            updated_node: cst.ClassDef,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_ClassDef(original_node, updated_node)
        return self._leave_stmt(original_node, final_node)

    def visit_With(self, node: cst.With) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_With(node)

    def leave_With(
            self,
            original_node: cst.With,
            updated_node: cst.With,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_With(original_node, updated_node)
        return self._leave_stmt(original_node, final_node)

    def visit_For(self, node: cst.For) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_For(node)

    def leave_For(
            self,
            original_node: cst.For,
            updated_node: cst.For,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_For(original_node, updated_node)
        return self._leave_stmt(original_node, final_node)

    def visit_While(self, node: cst.While) -> Optional[bool]:
        self._visit_stmt(node)
        return super().visit_While(node)

    def leave_While(
            self,
            original_node: cst.While,
            updated_node: cst.While,
    ) -> Union[cst.BaseStatement, cst.RemovalSentinel]:
        final_node = super().leave_While(original_node, updated_node)
        return self._leave_stmt(original_node, final_node)
