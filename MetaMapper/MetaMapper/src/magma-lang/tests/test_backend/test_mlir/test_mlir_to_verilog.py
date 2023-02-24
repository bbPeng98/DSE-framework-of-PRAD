import io
import pytest
from typing import Optional

import magma as m
from magma.backend.mlir.mlir_to_verilog import (
    mlir_to_verilog,
    circt_opt_binary_exists,
    MlirToVerilogError,
    MlirToVerilogOpts,
)
from magma.testing.utils import with_config


_with_nonexistent_circt_home = with_config(
    "circt_home", "/this_isnt_a_real_directory/"
)


def _skip_if_circt_opt_binary_does_not_exist():
    if not circt_opt_binary_exists():
        pytest.skip("no circt-opt binary found")


def _run_test(input_: Optional[str] = None, **kwargs):
    istream = io.TextIOWrapper(io.BytesIO())
    ostream = io.TextIOWrapper(io.BytesIO())
    if input_ is not None:
        istream.write(input_)
        istream.seek(0)
    opts = MlirToVerilogOpts(**kwargs)
    mlir_to_verilog(istream.buffer, ostream.buffer, opts)
    return istream, ostream


def test_no_binary(_with_nonexistent_circt_home):
    with pytest.raises(FileNotFoundError):
        _run_test()


def test_basic():
    _skip_if_circt_opt_binary_does_not_exist()
    _, __ = _run_test()


def test_module():
    _skip_if_circt_opt_binary_does_not_exist()
    _, ostream = _run_test("module {}\n")
    ostream.seek(0)
    assert (
        ostream.read() == (
            "// Generated by CIRCT circtorg-0.0.0-1018-g3a39b339f\n"
        )
    )


def test_bad_input():
    _skip_if_circt_opt_binary_does_not_exist()
    with pytest.raises(MlirToVerilogError):
        _run_test("blahblahblah")


@pytest.mark.parametrize("style", ("plain", "wrapInAtSquareBracket", "none"))
def test_location_info_style(style):
    _skip_if_circt_opt_binary_does_not_exist()
    ir = (
        """
        module attributes {{circt.loweringOptions = "locationInfoStyle={style}"}} {{
          hw.module @M() -> () {{}}
        }}
        """
    )
    ir = ir.format(style=style)
    _, ostream = _run_test(ir)
    ostream.seek(0)
    ostream.readline()  # skip header
    line = ostream.readline().rstrip()
    expected = "module M();"
    if style == "plain":
        expected += "	// <stdin>:3:11"
    elif style == "wrapInAtSquareBracket":
        expected += "	// @[<stdin>:3:11]"
    assert line == expected


@pytest.mark.parametrize("explicit_bitcast", (False, True))
def test_explicit_bitcast(explicit_bitcast):
    _skip_if_circt_opt_binary_does_not_exist()
    explicit_bitcast_attr = ",explicitBitcast" if explicit_bitcast else ""
    ir = (
        """
        module attributes {{circt.loweringOptions = "locationInfoStyle=none{explicit_bitcast_attr}"}} {{
            hw.module @M(%a: i8, %b: i8) -> (y: i8) {{
              %0 = comb.add %a, %b : i8
              hw.output %0 : i8
            }}
        }}
        """
    )
    ir = ir.format(explicit_bitcast_attr=explicit_bitcast_attr)
    _, ostream = _run_test(ir)
    ostream.seek(0)
    # Skip first 5 lines (incl. header).
    for _ in range(6):
        ostream.readline()
    line = ostream.readline().strip()
    if not explicit_bitcast:
        expected = "assign y = a + b;"
    else:
        expected = "assign y = 8'(a + b);"
    assert line == expected


@pytest.mark.parametrize("disallow_expression_inlining_in_ports", (False, True))
def test_disallow_expression_inlining_in_ports(disallow_expression_inlining_in_ports):
    _skip_if_circt_opt_binary_does_not_exist()
    disallow_expression_inlining_in_ports_attr = (
        ",disallowExpressionInliningInPorts"
        if disallow_expression_inlining_in_ports
        else ""
    )

    ir = (
        """
        module attributes {{circt.loweringOptions = "locationInfoStyle=none{disallow_expression_inlining_in_ports_attr}"}} {{
          hw.module.extern @Foo(%I: i1) -> (O: i1)
          hw.module @M(%I: i1) -> (O: i1) {{
              %1 = hw.constant -1 : i1
              %0 = comb.xor %1, %I : i1
              %2 = hw.instance "foo" @Foo(I: %0: i1) -> (O: i1)
              hw.output %2 : i1
          }}
        }}
        """
    )
    ir = ir.format(
        disallow_expression_inlining_in_ports_attr=disallow_expression_inlining_in_ports_attr
    )
    _, ostream = _run_test(ir)
    ostream.seek(0)
    found = False
    while True:
        line = ostream.readline().strip()
        if line.startswith(".I"):
            found = True
            break
    assert found
    if not disallow_expression_inlining_in_ports_attr:
        assert line == ".I (~I),"
    else:
        assert line == ".I (_foo_I),"
