from modules.number_theory import euler_totient
from modules.euclidean_algorithm import gcd
from modules.modular_arithmetic import modular_inverse

def generate_keys(p, q, e):
    n = p * q
    phi = euler_totient(n)

    if gcd(e, phi) != 1:
        raise ValueError("e must be coprime to φ(n)")

    d = modular_inverse(e, phi)
    return (n, e), (n, d)  # public key, private key

def encrypt(message, public_key):
    n, e = public_key
    return pow(message, e, n)

def decrypt(ciphertext, private_key):
    n, d = private_key
    return pow(ciphertext, d, n)