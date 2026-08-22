from modules.rsa import decrypt, encrypt
from modules.text_encoding import numbers_to_text, text_to_numbers

def encrypt_text(text, public_key):
    numbers = text_to_numbers(text)
    return [encrypt(number, public_key) for number in numbers]

def decrypt_text(ciphertext, private_key):
    numbers = [decrypt(value, private_key) for value in ciphertext]
    return numbers_to_text(numbers)

def encryption_steps(text, public_key):
    n, e = public_key
    numbers = text_to_numbers(text)

    steps = []
    for char, number in zip(text, numbers):
        ciphertext = encrypt(number, public_key)

        steps.append({
            "char": char,   
            "number": number,
            "formula": f"{number}^{e} mod {n}",
            "ciphertext": ciphertext,
        })
    return steps  

def decryption_steps(ciphertext, private_key):
    n, d = private_key

    steps = []
    for value in ciphertext:
        decrypted = decrypt(value, private_key)

        steps.append({
            "ciphertext": value,
            "formula": f"{value}^{d} mod {n}",
            "number": decrypted,
        })
    return steps     