from modules.rsa import generate_keys
from modules.rsa_message import decrypt_text, encrypt_text

def test_encrypt_and_decrypt_text():
    public_key, private_key = generate_keys(61, 53, 17)

    message = "HELLO"
    ciphertext = encrypt_text(message, public_key)
    decrypted_message = decrypt_text(ciphertext, private_key)       

    assert decrypted_message == message