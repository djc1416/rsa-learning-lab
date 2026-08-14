import pytest
from modules.modular_arithmetic import modular_power, modular_power_manual, modular_inverse


def test_modular_power():
    assert modular_power(2, 5, 7) == 4
    assert modular_power(3, 4, 5) == 1

def test_modular_power_manual():
    assert modular_power_manual(2, 5, 7) == 4
    assert modular_power_manual(3, 4, 5) == 1
    assert modular_power_manual(2, 100, 7) == 2
    assert modular_power_manual(10, 0, 7) == 1
    assert modular_power_manual(7, 3, 5) == 3

def test_modular_inverse():
    assert modular_inverse(17, 5) == 3
    assert modular_inverse(3, 11) == 4   

def test_modular_inverse_does_not_exist():
    with pytest.raises(ValueError):
        modular_inverse(6, 9)    