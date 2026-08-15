from modules.text_encoding import numbers_to_text, text_to_numbers

def test_text_to_numbers():
    assert text_to_numbers("ABC") == [65, 66, 67]

def test_numbers_to_text():
        assert numbers_to_text([65, 66, 67]) == "ABC"

def test_text_round_trip():
    message = "HELLO"

    assert numbers_to_text(text_to_numbers(message)) == message