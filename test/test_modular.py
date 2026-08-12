from modules.modular_arithmetic import modular_power

def test_modular_power():
    assert modular_power(2, 5, 7) == 4
    assert modular_power(3, 4, 5) == 1