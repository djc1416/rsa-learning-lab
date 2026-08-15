def text_to_numbers(text):
    return [ord(char) for char in text]

def numbers_to_text(numbers):
    return "".join(chr(number) for number in numbers
                   )