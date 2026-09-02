from modules.rsa import generate_keys, encrypt, decrypt
import pytest

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

def test_rejects_non_prime_p():
    with pytest.raises(ValueError):
        generate_keys(4, 11, 3)

def test_rejects_non_prime_q():
    with pytest.raises(ValueError):
        generate_keys(5, 9, 3)

def test_rejects_equal_primes():
    with pytest.raises(ValueError):
        generate_keys(5, 5, 3)                

def test_rejects_invalid_e():
    with pytest.raises(ValueError):
        generate_keys(61, 53, 1)    

def test_generate_large_keys():
    public_key, private_key = generate_keys(61, 53, 17)

    assert public_key == (3233, 17)
    assert private_key == (3233, 2753)       

def test_larger_rsa_encyption():
    public_key, private_key = generate_keys(61, 53, 17)
    message = 72
    
    ciphertext = encrypt(message, public_key)
    decrypted_message = decrypt(ciphertext, private_key)

    assert decrypted_message == message   