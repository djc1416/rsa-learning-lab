from modules.rsa import decrypt, encrypt
from modules.text_encoding import numbers_to_text, text_to_numbers

def encrypt_text(text, public_key):
    numbers = text_to_numbers(text)
    return [encrypt(number, public_key) for number in numbers]

def decrypt_text(ciphertext, private_key):
    numbers = [decrypt(value, private_key) for value in ciphertext]
    return numbers_to_text(numbers)