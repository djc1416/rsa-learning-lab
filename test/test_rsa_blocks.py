import pytest

from modules.rsa_blocks import split_into_blocks

def test_split_into_blocks():
    assert split_into_blocks([10, 20, 30], 55) == [10, 20, 30]

def test_block_cannot_exceed_modulus():
    with pytest.raises(ValueError):
        split_into_blocks([72], 55)
