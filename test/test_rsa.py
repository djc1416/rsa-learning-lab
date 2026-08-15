from modules.rsa import generate_keys, encrypt, decrypt

def test_generate_keys():
    public_key, private_key = generate_keys(5, 11, 3)

    assert public_key == (55, 3)
    assert private_key == (55, 27)  

def test_encrypt_and_decrypt():
    public_key, private_key = generate_keys(5, 11, 3)
    message = 7
    ciphertext = encrypt(message, public_key)
    decrypted_message = decrypt(ciphertext, private_key)

    assert decrypted_message == message    

    