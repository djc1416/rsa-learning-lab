from modules.rsa import encrypt, generate_keys
from modules.rsa_message import decrypt_text, encrypt_text, encryption_steps

def test_encrypt_and_decrypt_text():
    public_key, private_key = generate_keys(61, 53, 17)

    message = "HELLO"
    ciphertext = encrypt_text(message, public_key)
    decrypted_message = decrypt_text(ciphertext, private_key)       

    assert decrypted_message == message

def test_encryption_steps():
    public_key, _ = generate_keys(61, 53, 17)

    steps = encryption_steps("HI", public_key)

    assert steps[0]["char"] == "H"
    assert steps[0]["number"] == 72
    assert steps[0]["ciphertext"] == 3000    

    assert steps[1]["char"] == "I"
    assert steps[1]["number"] == 73