from modules.extended_euclidean import extended_gcd


def modular_inverse(a, modulus):
    gcd, x, _ = extended_gcd(a, modulus)
    if gcd != 1:
        raise ValueError(f"No modular inverse exists for {a} modulo {modulus}")
    return x % modulus

def modular_power(base, exponent, modulus):
    return pow(base, exponent, modulus)

def modular_power_manual(base, exponent, modulus):
    result = 1

    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        base = (base * base) % modulus
        exponent //= 2    
    return result