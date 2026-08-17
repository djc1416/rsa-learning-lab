def split_into_blocks(numbers, modulus):
    blocks = []

    for number in numbers:
        if number >= modulus:
            raise ValueError("Message value is too large for the modulus.")

        blocks.append(number)

    return blocks    