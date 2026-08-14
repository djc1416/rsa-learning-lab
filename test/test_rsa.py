from modules.rsa import generate_keys

def test_generate_keys():
    public_key, private_key = generate_keys(5, 11, 3)

    assert public_key == (55, 3)
    assert private_key == (55, 27)  
    