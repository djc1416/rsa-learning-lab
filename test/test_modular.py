from modules.modular_arithmetic import modular_power, modular_power_manual

def test_modular_power():
    assert modular_power(2, 5, 7) == 4
    assert modular_power(3, 4, 5) == 1

def test_modular_power_manual():
    assert modular_power_manual(2, 5, 7) == 4
    assert modular_power_manual(3, 4, 5) == 1
    assert modular_power_manual(2, 100, 7) == 2