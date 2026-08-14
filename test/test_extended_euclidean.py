from modules.extended_euclidean import extended_gcd

def test_extended_gcd():
    gcd, x, y = extended_gcd(17, 5)

    assert gcd == 1
    assert 17 * x + 5 * y == gcd

def test_extended_gcd_non_coprime():
    gcd, x, y = extended_gcd(48, 18)

    assert gcd == 6
    assert 48 * x + 18 * y == gcd    