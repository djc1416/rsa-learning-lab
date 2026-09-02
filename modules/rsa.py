from modules.number_theory import euler_totient, is_prime
from modules.euclidean_algorithm import gcd
from modules.modular_arithmetic import modular_inverse

def generate_keys(p, q, e):
    if not is_prime(p) or not is_prime(q):
        raise ValueError("p and q must be prime")
    if p == q:
        raise ValueError("p and q must be different")
    
    n = p * q
    phi = euler_totient(n)

    if e <= 1 or e >= phi:
        raise ValueError("e must satisfy 1 < e < φ(n)")

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