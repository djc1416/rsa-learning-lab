from modules.number_theory import euler_totient, is_prime

def test_euler_totient():
    assert euler_totient(1) == 1
    assert euler_totient(5) == 4
    assert euler_totient(10) == 4
    assert euler_totient(12) == 4
    assert euler_totient(55) == 40

def test_is_prime():
    assert is_prime(2) is True
    assert is_prime(5) is True
    assert is_prime(11) is True
    assert is_prime(4)  is False
    assert is_prime(15) is False
    assert is_prime(1) is False