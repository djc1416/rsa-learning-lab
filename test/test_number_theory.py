from modules.number_theory import euler_totient

def test_euler_totient():
    assert euler_totient(1) == 1
    assert euler_totient(5) == 4
    assert euler_totient(10) == 4
    assert euler_totient(12) == 4
    assert euler_totient(55) == 40