from modules.rsa import decrypt, encrypt
from modules.text_encoding import numbers_to_text, text_to_numbers
from modules.rsa_blocks import split_into_blocks


def encrypt_text(text, public_key):
    numbers = text_to_numbers(text)
    n, _ = public_key
    blocks = split_into_blocks(numbers, n)

    return [encrypt(block, public_key) for block in blocks]


def decrypt_text(ciphertext, private_key):
    numbers = [decrypt(value, private_key) for value in ciphertext]
    return numbers_to_text(numbers)


def encryption_steps(text, public_key):
    n, e = public_key
    numbers = text_to_numbers(text)
    blocks = split_into_blocks(numbers, n)

    steps = []

    for char, block in zip(text, blocks):
        ciphertext = encrypt(block, public_key)

        steps.append({
            "char": char,
            "number": block,
            "formula": f"{block}^{e} mod {n}",
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