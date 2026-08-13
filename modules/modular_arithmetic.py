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