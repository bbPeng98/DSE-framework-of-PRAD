# file generated by /aha/ast_tools/util/generate_ast/generate.py on 2022-08-12 19:00:55.939469
# for python 3.8.10 (default, Jun 22 2022, 20:18:18)

import ast
import sys
import typing as tp
import warnings

if sys.version_info[:2] != (3, 8):
    warnings.warn(f"{__file__} generated for (3, 8)"
                  f"does not match system version {sys.version_info[:2]}")

__ALL__ = ['AST', 'alias', 'arg', 'arguments', 'boolop', 'And', 'Or', 'cmpop', 'Eq', 'Gt', 'GtE', 'In', 'Is', 'IsNot', 'Lt', 'LtE', 'NotEq', 'NotIn', 'comprehension', 'excepthandler', 'ExceptHandler', 'expr', 'Attribute', 'Await', 'BinOp', 'BoolOp', 'Call', 'Compare', 'Constant', 'Bytes', 'Ellipsis', 'NameConstant', 'Num', 'Str', 'Dict', 'DictComp', 'FormattedValue', 'GeneratorExp', 'IfExp', 'JoinedStr', 'Lambda', 'List', 'ListComp', 'Name', 'NamedExpr', 'Set', 'SetComp', 'Starred', 'Subscript', 'Tuple', 'UnaryOp', 'Yield', 'YieldFrom', 'expr_context', 'AugLoad', 'AugStore', 'Del', 'Load', 'Param', 'Store', 'keyword', 'mod', 'Expression', 'FunctionType', 'Interactive', 'Module', 'Suite', 'operator', 'Add', 'BitAnd', 'BitOr', 'BitXor', 'Div', 'FloorDiv', 'LShift', 'MatMult', 'Mod', 'Mult', 'Pow', 'RShift', 'Sub', 'slice', 'ExtSlice', 'Index', 'Slice', 'stmt', 'AnnAssign', 'Assert', 'Assign', 'AsyncFor', 'AsyncFunctionDef', 'AsyncWith', 'AugAssign', 'Break', 'ClassDef', 'Continue', 'Delete', 'Expr', 'For', 'FunctionDef', 'Global', 'If', 'Import', 'ImportFrom', 'Nonlocal', 'Pass', 'Raise', 'Return', 'Try', 'While', 'With', 'type_ignore', 'TypeIgnore', 'unaryop', 'Invert', 'Not', 'UAdd', 'USub', 'withitem']

__ALL__ += ['immutable', 'mutable', 'parse', 'dump',
			'iter_fields', 'iter_child_nodes', 'walk',
			'NodeVisitor', 'NodeTransformer']


def _cast_tree(seq_t, n_seq_t, type_look_up, tree):
    args = seq_t, n_seq_t, type_look_up

    if isinstance(tree, seq_t):
        return n_seq_t(_cast_tree(*args, c) for c in tree)

    try:
        T = type_look_up[type(tree)]
    except KeyError:
        return tree

    kwargs = {}
    for field, c in iter_fields(tree):
        kwargs[field] = _cast_tree(*args, c)

    return T(**kwargs)


def immutable(tree: ast.AST) -> 'AST':
    '''Converts a mutable ast to an immutable one'''
    return _cast_tree(list, tuple, ImmutableMeta._mutable_to_immutable, tree)

def mutable(tree: 'AST') -> ast.AST:
    '''Converts an immutable ast to a mutable one'''
    return _cast_tree(tuple, list, ImmutableMeta._immutable_to_mutable, tree)

def parse(source, filename='<unknown>', mode='exec') -> 'AST':
    tree = ast.parse(source, filename, mode)
    return immutable(tree)

def dump(node, annotate_fields=True, include_attributes=False) -> str:
    tree = mutable(node)
    return ast.dump(tree)


# duck typing ftw
iter_fields = ast.iter_fields

# The following is more or less copied verbatim from
# CPython/Lib/ast.py. Changes are:
# s/list/tuple/
#
# The CPython license is very permissive so I am pretty sure this is cool.
# If it is not Guido please forgive me.
def iter_child_nodes(node):
    for name, field in iter_fields(node):
        if isinstance(field, AST):
            yield field
        elif isinstance(field, tuple):
            for item in field:
                if isinstance(item, AST):
                    yield item

# Same note as above
def walk(node):
    from collections import deque
    todo = deque([node])
    while todo:
        node = todo.popleft()
        todo.extend(iter_child_nodes(node))
        yield node


# Same note as above
class NodeVisitor:
    def visit(self, node):
        method = 'visit_' + node.__class__.__name__
        visitor = getattr(self, method, self.generic_visit)
        return visitor(node)

    def generic_visit(self, node):
        for field, value in iter_fields(node):
            if isinstance(value,  tuple):
                for item in value:
                    if isinstance(item, AST):
                        self.visit(item)
            elif isinstance(value, AST):
                self.visit(value)


# Same note as above
class NodeTransformer(NodeVisitor):
    '''
    Mostly equivalent to ast.NodeTransformer, except returns new nodes
    instead of mutating them in place
    '''

    def generic_visit(self, node):
        kwargs = {}
        for field, old_value in iter_fields(node):
            if isinstance(old_value, tuple):
                new_value = []
                for value in old_value:
                    if isinstance(value, AST):
                        value = self.visit(value)
                        if value is None:
                            continue
                        elif not isinstance(value, AST):
                            new_value.extend(value)
                            continue
                    new_value.append(value)
                new_value = tuple(new_value)
            elif isinstance(type(old_value), ImmutableMeta):
                new_value = self.visit(old_value)
            else:
                new_value = old_value
            kwargs[field] = new_value
        return type(node)(**kwargs)


__ALL__ += ['ImmutableMeta']

class ImmutableMeta(type):
    _immutable_to_mutable = dict()
    _mutable_to_immutable = dict()
    def __new__(mcs, name, bases, namespace, mutable, **kwargs):
        cls = super().__new__(mcs, name, bases, namespace, **kwargs)
        ImmutableMeta._immutable_to_mutable[cls] = mutable
        ImmutableMeta._mutable_to_immutable[mutable] = cls

        return cls

    def __instancecheck__(cls, instance):
        return super().__instancecheck__(instance)\
                or isinstance(instance, ImmutableMeta._immutable_to_mutable[cls])

    def __subclasscheck__(cls, type_):
        return super().__subclasscheck__(type_)\
                or issubclass(type_, ImmutableMeta._immutable_to_mutable[cls])


class AST(mutable=ast.AST, metaclass=ImmutableMeta):
    def __setattr__(self, attr, value):
        if attr in self._fields and hasattr(self, attr):
            raise AttributeError('Cannot modify ImmutableAST fields')
        elif isinstance(value, (list, ast.AST)):
            value = immutable(value)

        self.__dict__[attr] = value

    def __delattr__(self, attr):
        if attr in self._fields:
            raise AttributeError('Cannot modify ImmutableAST fields')
        del self.__dict__[attr]

    def __hash__(self):
        try:
            return self._hash_
        except AttributeError:
            pass

        h = hash(type(self))
        for _, n in iter_fields(self):
            if isinstance(n, AST):
                h += hash(n)
            elif isinstance(n, tp.Sequence):
                for c in n:
                    h += hash(c)
            else:
                h += hash(n)
        self._hash_ = h
        return h

    def __eq__(self, other):
        if not isinstance(other, type(self)):
            return NotImplemented
        elif type(self) == type(other):
            for f in self._fields:
                if getattr(self, f) != getattr(other, f):
                    return False
            return True
        else:
            return False

    def __ne__(self, other):
        return not (self == other)


class alias(AST, mutable=ast.alias):
    _fields=('name', 'asname')
    def __init__(self, name, asname):
        self.name = name
        self.asname = asname

class arg(AST, mutable=ast.arg):
    _fields=('arg', 'annotation', 'type_comment')
    def __init__(self, arg, annotation, type_comment):
        self.arg = arg
        self.annotation = annotation
        self.type_comment = type_comment

class arguments(AST, mutable=ast.arguments):
    _fields=('posonlyargs', 'args', 'vararg', 'kwonlyargs', 'kw_defaults', 'kwarg', 'defaults')
    def __init__(self, posonlyargs, args, vararg, kwonlyargs, kw_defaults, kwarg, defaults):
        self.posonlyargs = posonlyargs
        self.args = args
        self.vararg = vararg
        self.kwonlyargs = kwonlyargs
        self.kw_defaults = kw_defaults
        self.kwarg = kwarg
        self.defaults = defaults

class boolop(AST, mutable=ast.boolop):
    _fields=()
    def __init__(self):
        pass

class And(boolop, mutable=ast.And):
    _fields=()
    def __init__(self):
        pass

class Or(boolop, mutable=ast.Or):
    _fields=()
    def __init__(self):
        pass

class cmpop(AST, mutable=ast.cmpop):
    _fields=()
    def __init__(self):
        pass

class Eq(cmpop, mutable=ast.Eq):
    _fields=()
    def __init__(self):
        pass

class Gt(cmpop, mutable=ast.Gt):
    _fields=()
    def __init__(self):
        pass

class GtE(cmpop, mutable=ast.GtE):
    _fields=()
    def __init__(self):
        pass

class In(cmpop, mutable=ast.In):
    _fields=()
    def __init__(self):
        pass

class Is(cmpop, mutable=ast.Is):
    _fields=()
    def __init__(self):
        pass

class IsNot(cmpop, mutable=ast.IsNot):
    _fields=()
    def __init__(self):
        pass

class Lt(cmpop, mutable=ast.Lt):
    _fields=()
    def __init__(self):
        pass

class LtE(cmpop, mutable=ast.LtE):
    _fields=()
    def __init__(self):
        pass

class NotEq(cmpop, mutable=ast.NotEq):
    _fields=()
    def __init__(self):
        pass

class NotIn(cmpop, mutable=ast.NotIn):
    _fields=()
    def __init__(self):
        pass

class comprehension(AST, mutable=ast.comprehension):
    _fields=('target', 'iter', 'ifs', 'is_async')
    def __init__(self, target, iter, ifs, is_async):
        self.target = target
        self.iter = iter
        self.ifs = ifs
        self.is_async = is_async

class excepthandler(AST, mutable=ast.excepthandler):
    _fields=()
    def __init__(self):
        pass

class ExceptHandler(excepthandler, mutable=ast.ExceptHandler):
    _fields=('type', 'name', 'body')
    def __init__(self, type, name, body):
        self.type = type
        self.name = name
        self.body = body

class expr(AST, mutable=ast.expr):
    _fields=()
    def __init__(self):
        pass

class Attribute(expr, mutable=ast.Attribute):
    _fields=('value', 'attr', 'ctx')
    def __init__(self, value, attr, ctx):
        self.value = value
        self.attr = attr
        self.ctx = ctx

class Await(expr, mutable=ast.Await):
    _fields=('value',)
    def __init__(self, value):
        self.value = value

class BinOp(expr, mutable=ast.BinOp):
    _fields=('left', 'op', 'right')
    def __init__(self, left, op, right):
        self.left = left
        self.op = op
        self.right = right

class BoolOp(expr, mutable=ast.BoolOp):
    _fields=('op', 'values')
    def __init__(self, op, values):
        self.op = op
        self.values = values

class Call(expr, mutable=ast.Call):
    _fields=('func', 'args', 'keywords')
    def __init__(self, func, args, keywords):
        self.func = func
        self.args = args
        self.keywords = keywords

class Compare(expr, mutable=ast.Compare):
    _fields=('left', 'ops', 'comparators')
    def __init__(self, left, ops, comparators):
        self.left = left
        self.ops = ops
        self.comparators = comparators

class Constant(expr, mutable=ast.Constant):
    _fields=('value', 'kind')
    def __init__(self, value, kind):
        self.value = value
        self.kind = kind

class Bytes(Constant, mutable=ast.Bytes):
    _fields=('s',)
    def __init__(self, s):
        self.s = s

class Ellipsis(Constant, mutable=ast.Ellipsis):
    _fields=()
    def __init__(self):
        pass

class NameConstant(Constant, mutable=ast.NameConstant):
    _fields=('value', 'kind')
    def __init__(self, value, kind):
        self.value = value
        self.kind = kind

class Num(Constant, mutable=ast.Num):
    _fields=('n',)
    def __init__(self, n):
        self.n = n

class Str(Constant, mutable=ast.Str):
    _fields=('s',)
    def __init__(self, s):
        self.s = s

class Dict(expr, mutable=ast.Dict):
    _fields=('keys', 'values')
    def __init__(self, keys, values):
        self.keys = keys
        self.values = values

class DictComp(expr, mutable=ast.DictComp):
    _fields=('key', 'value', 'generators')
    def __init__(self, key, value, generators):
        self.key = key
        self.value = value
        self.generators = generators

class FormattedValue(expr, mutable=ast.FormattedValue):
    _fields=('value', 'conversion', 'format_spec')
    def __init__(self, value, conversion, format_spec):
        self.value = value
        self.conversion = conversion
        self.format_spec = format_spec

class GeneratorExp(expr, mutable=ast.GeneratorExp):
    _fields=('elt', 'generators')
    def __init__(self, elt, generators):
        self.elt = elt
        self.generators = generators

class IfExp(expr, mutable=ast.IfExp):
    _fields=('test', 'body', 'orelse')
    def __init__(self, test, body, orelse):
        self.test = test
        self.body = body
        self.orelse = orelse

class JoinedStr(expr, mutable=ast.JoinedStr):
    _fields=('values',)
    def __init__(self, values):
        self.values = values

class Lambda(expr, mutable=ast.Lambda):
    _fields=('args', 'body')
    def __init__(self, args, body):
        self.args = args
        self.body = body

class List(expr, mutable=ast.List):
    _fields=('elts', 'ctx')
    def __init__(self, elts, ctx):
        self.elts = elts
        self.ctx = ctx

class ListComp(expr, mutable=ast.ListComp):
    _fields=('elt', 'generators')
    def __init__(self, elt, generators):
        self.elt = elt
        self.generators = generators

class Name(expr, mutable=ast.Name):
    _fields=('id', 'ctx')
    def __init__(self, id, ctx):
        self.id = id
        self.ctx = ctx

class NamedExpr(expr, mutable=ast.NamedExpr):
    _fields=('target', 'value')
    def __init__(self, target, value):
        self.target = target
        self.value = value

class Set(expr, mutable=ast.Set):
    _fields=('elts',)
    def __init__(self, elts):
        self.elts = elts

class SetComp(expr, mutable=ast.SetComp):
    _fields=('elt', 'generators')
    def __init__(self, elt, generators):
        self.elt = elt
        self.generators = generators

class Starred(expr, mutable=ast.Starred):
    _fields=('value', 'ctx')
    def __init__(self, value, ctx):
        self.value = value
        self.ctx = ctx

class Subscript(expr, mutable=ast.Subscript):
    _fields=('value', 'slice', 'ctx')
    def __init__(self, value, slice, ctx):
        self.value = value
        self.slice = slice
        self.ctx = ctx

class Tuple(expr, mutable=ast.Tuple):
    _fields=('elts', 'ctx')
    def __init__(self, elts, ctx):
        self.elts = elts
        self.ctx = ctx

class UnaryOp(expr, mutable=ast.UnaryOp):
    _fields=('op', 'operand')
    def __init__(self, op, operand):
        self.op = op
        self.operand = operand

class Yield(expr, mutable=ast.Yield):
    _fields=('value',)
    def __init__(self, value):
        self.value = value

class YieldFrom(expr, mutable=ast.YieldFrom):
    _fields=('value',)
    def __init__(self, value):
        self.value = value

class expr_context(AST, mutable=ast.expr_context):
    _fields=()
    def __init__(self):
        pass

class AugLoad(expr_context, mutable=ast.AugLoad):
    _fields=()
    def __init__(self):
        pass

class AugStore(expr_context, mutable=ast.AugStore):
    _fields=()
    def __init__(self):
        pass

class Del(expr_context, mutable=ast.Del):
    _fields=()
    def __init__(self):
        pass

class Load(expr_context, mutable=ast.Load):
    _fields=()
    def __init__(self):
        pass

class Param(expr_context, mutable=ast.Param):
    _fields=()
    def __init__(self):
        pass

class Store(expr_context, mutable=ast.Store):
    _fields=()
    def __init__(self):
        pass

class keyword(AST, mutable=ast.keyword):
    _fields=('arg', 'value')
    def __init__(self, arg, value):
        self.arg = arg
        self.value = value

class mod(AST, mutable=ast.mod):
    _fields=()
    def __init__(self):
        pass

class Expression(mod, mutable=ast.Expression):
    _fields=('body',)
    def __init__(self, body):
        self.body = body

class FunctionType(mod, mutable=ast.FunctionType):
    _fields=('argtypes', 'returns')
    def __init__(self, argtypes, returns):
        self.argtypes = argtypes
        self.returns = returns

class Interactive(mod, mutable=ast.Interactive):
    _fields=('body',)
    def __init__(self, body):
        self.body = body

class Module(mod, mutable=ast.Module):
    _fields=('body', 'type_ignores')
    def __init__(self, body, type_ignores):
        self.body = body
        self.type_ignores = type_ignores

class Suite(mod, mutable=ast.Suite):
    _fields=('body',)
    def __init__(self, body):
        self.body = body

class operator(AST, mutable=ast.operator):
    _fields=()
    def __init__(self):
        pass

class Add(operator, mutable=ast.Add):
    _fields=()
    def __init__(self):
        pass

class BitAnd(operator, mutable=ast.BitAnd):
    _fields=()
    def __init__(self):
        pass

class BitOr(operator, mutable=ast.BitOr):
    _fields=()
    def __init__(self):
        pass

class BitXor(operator, mutable=ast.BitXor):
    _fields=()
    def __init__(self):
        pass

class Div(operator, mutable=ast.Div):
    _fields=()
    def __init__(self):
        pass

class FloorDiv(operator, mutable=ast.FloorDiv):
    _fields=()
    def __init__(self):
        pass

class LShift(operator, mutable=ast.LShift):
    _fields=()
    def __init__(self):
        pass

class MatMult(operator, mutable=ast.MatMult):
    _fields=()
    def __init__(self):
        pass

class Mod(operator, mutable=ast.Mod):
    _fields=()
    def __init__(self):
        pass

class Mult(operator, mutable=ast.Mult):
    _fields=()
    def __init__(self):
        pass

class Pow(operator, mutable=ast.Pow):
    _fields=()
    def __init__(self):
        pass

class RShift(operator, mutable=ast.RShift):
    _fields=()
    def __init__(self):
        pass

class Sub(operator, mutable=ast.Sub):
    _fields=()
    def __init__(self):
        pass

class slice(AST, mutable=ast.slice):
    _fields=()
    def __init__(self):
        pass

class ExtSlice(slice, mutable=ast.ExtSlice):
    _fields=('dims',)
    def __init__(self, dims):
        self.dims = dims

class Index(slice, mutable=ast.Index):
    _fields=('value',)
    def __init__(self, value):
        self.value = value

class Slice(slice, mutable=ast.Slice):
    _fields=('lower', 'upper', 'step')
    def __init__(self, lower, upper, step):
        self.lower = lower
        self.upper = upper
        self.step = step

class stmt(AST, mutable=ast.stmt):
    _fields=()
    def __init__(self):
        pass

class AnnAssign(stmt, mutable=ast.AnnAssign):
    _fields=('target', 'annotation', 'value', 'simple')
    def __init__(self, target, annotation, value, simple):
        self.target = target
        self.annotation = annotation
        self.value = value
        self.simple = simple

class Assert(stmt, mutable=ast.Assert):
    _fields=('test', 'msg')
    def __init__(self, test, msg):
        self.test = test
        self.msg = msg

class Assign(stmt, mutable=ast.Assign):
    _fields=('targets', 'value', 'type_comment')
    def __init__(self, targets, value, type_comment):
        self.targets = targets
        self.value = value
        self.type_comment = type_comment

class AsyncFor(stmt, mutable=ast.AsyncFor):
    _fields=('target', 'iter', 'body', 'orelse', 'type_comment')
    def __init__(self, target, iter, body, orelse, type_comment):
        self.target = target
        self.iter = iter
        self.body = body
        self.orelse = orelse
        self.type_comment = type_comment

class AsyncFunctionDef(stmt, mutable=ast.AsyncFunctionDef):
    _fields=('name', 'args', 'body', 'decorator_list', 'returns', 'type_comment')
    def __init__(self, name, args, body, decorator_list, returns, type_comment):
        self.name = name
        self.args = args
        self.body = body
        self.decorator_list = decorator_list
        self.returns = returns
        self.type_comment = type_comment

class AsyncWith(stmt, mutable=ast.AsyncWith):
    _fields=('items', 'body', 'type_comment')
    def __init__(self, items, body, type_comment):
        self.items = items
        self.body = body
        self.type_comment = type_comment

class AugAssign(stmt, mutable=ast.AugAssign):
    _fields=('target', 'op', 'value')
    def __init__(self, target, op, value):
        self.target = target
        self.op = op
        self.value = value

class Break(stmt, mutable=ast.Break):
    _fields=()
    def __init__(self):
        pass

class ClassDef(stmt, mutable=ast.ClassDef):
    _fields=('name', 'bases', 'keywords', 'body', 'decorator_list')
    def __init__(self, name, bases, keywords, body, decorator_list):
        self.name = name
        self.bases = bases
        self.keywords = keywords
        self.body = body
        self.decorator_list = decorator_list

class Continue(stmt, mutable=ast.Continue):
    _fields=()
    def __init__(self):
        pass

class Delete(stmt, mutable=ast.Delete):
    _fields=('targets',)
    def __init__(self, targets):
        self.targets = targets

class Expr(stmt, mutable=ast.Expr):
    _fields=('value',)
    def __init__(self, value):
        self.value = value

class For(stmt, mutable=ast.For):
    _fields=('target', 'iter', 'body', 'orelse', 'type_comment')
    def __init__(self, target, iter, body, orelse, type_comment):
        self.target = target
        self.iter = iter
        self.body = body
        self.orelse = orelse
        self.type_comment = type_comment

class FunctionDef(stmt, mutable=ast.FunctionDef):
    _fields=('name', 'args', 'body', 'decorator_list', 'returns', 'type_comment')
    def __init__(self, name, args, body, decorator_list, returns, type_comment):
        self.name = name
        self.args = args
        self.body = body
        self.decorator_list = decorator_list
        self.returns = returns
        self.type_comment = type_comment

class Global(stmt, mutable=ast.Global):
    _fields=('names',)
    def __init__(self, names):
        self.names = names

class If(stmt, mutable=ast.If):
    _fields=('test', 'body', 'orelse')
    def __init__(self, test, body, orelse):
        self.test = test
        self.body = body
        self.orelse = orelse

class Import(stmt, mutable=ast.Import):
    _fields=('names',)
    def __init__(self, names):
        self.names = names

class ImportFrom(stmt, mutable=ast.ImportFrom):
    _fields=('module', 'names', 'level')
    def __init__(self, module, names, level):
        self.module = module
        self.names = names
        self.level = level

class Nonlocal(stmt, mutable=ast.Nonlocal):
    _fields=('names',)
    def __init__(self, names):
        self.names = names

class Pass(stmt, mutable=ast.Pass):
    _fields=()
    def __init__(self):
        pass

class Raise(stmt, mutable=ast.Raise):
    _fields=('exc', 'cause')
    def __init__(self, exc, cause):
        self.exc = exc
        self.cause = cause

class Return(stmt, mutable=ast.Return):
    _fields=('value',)
    def __init__(self, value):
        self.value = value

class Try(stmt, mutable=ast.Try):
    _fields=('body', 'handlers', 'orelse', 'finalbody')
    def __init__(self, body, handlers, orelse, finalbody):
        self.body = body
        self.handlers = handlers
        self.orelse = orelse
        self.finalbody = finalbody

class While(stmt, mutable=ast.While):
    _fields=('test', 'body', 'orelse')
    def __init__(self, test, body, orelse):
        self.test = test
        self.body = body
        self.orelse = orelse

class With(stmt, mutable=ast.With):
    _fields=('items', 'body', 'type_comment')
    def __init__(self, items, body, type_comment):
        self.items = items
        self.body = body
        self.type_comment = type_comment

class type_ignore(AST, mutable=ast.type_ignore):
    _fields=()
    def __init__(self):
        pass

class TypeIgnore(type_ignore, mutable=ast.TypeIgnore):
    _fields=('lineno', 'tag')
    def __init__(self, lineno, tag):
        self.lineno = lineno
        self.tag = tag

class unaryop(AST, mutable=ast.unaryop):
    _fields=()
    def __init__(self):
        pass

class Invert(unaryop, mutable=ast.Invert):
    _fields=()
    def __init__(self):
        pass

class Not(unaryop, mutable=ast.Not):
    _fields=()
    def __init__(self):
        pass

class UAdd(unaryop, mutable=ast.UAdd):
    _fields=()
    def __init__(self):
        pass

class USub(unaryop, mutable=ast.USub):
    _fields=()
    def __init__(self):
        pass

class withitem(AST, mutable=ast.withitem):
    _fields=('context_expr', 'optional_vars')
    def __init__(self, context_expr, optional_vars):
        self.context_expr = context_expr
        self.optional_vars = optional_vars

