

def set_debug_mode(value: bool = True):
    global __DEBUG_MODE
    assert value in {True, False}
    __DEBUG_MODE = value


def get_debug_mode():
    return __DEBUG_MODE


