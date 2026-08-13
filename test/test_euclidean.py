from modules.euclidean_algorithm import gcd

def test_gcd():
    assert gcd(48, 18) == 6
    assert gcd(20, 8) == 4
    assert gcd(17, 5) == 1