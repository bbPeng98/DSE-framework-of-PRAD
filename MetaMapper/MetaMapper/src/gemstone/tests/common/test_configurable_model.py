import random
from hwtypes import BitVector
from gemstone.common.configurable_model import ConfigurableModel


def test_configurable_model_smoke():
    has_type_error = False
    try:
        my_model = ConfigurableModel(32, 32)()
    except TypeError as e:
        msg = e.__repr__()
        has_type_error = True
    assert has_type_error


def test_configurable_model_subclass():
    def value(v):
        return BitVector[32](v)

    class Foo(ConfigurableModel(32, 32)):
        def __init__(self):
            super().__init__()

        def __call__(self):
            return 0

    f = Foo()

    # Check normal operation of config.
    addr = value(random.randint(0, 2**32 - 1))
    data = value(random.randint(0, 2**32 - 1))
    f.config[addr] = data
    assert f.config[addr] == data
    assert f() == 0

    # Check that an address of the wrong type raises a value error.
    addr = BitVector[100](0)
    try:
        f.config[addr] = data
        assert False
    except ValueError as e:
        assert repr(e) == repr(ValueError("Expected addr to be of width 32"))

    # Check that reading a non-existent address raises a key error. We clear the
    # config by re-initializing foo.
    f = Foo()
    addr = value(0)
    try:
        print(f.config[addr])
        assert False
    except KeyError as e:
        assert repr(e) == repr(KeyError(0))
