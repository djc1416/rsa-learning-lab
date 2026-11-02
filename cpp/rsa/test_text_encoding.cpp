#include <iostream>
#include "text_encoding.hpp"

int main() {
    std::string message = "HELLO";

    std::vector<int> numbers = textToNumbers(message);

    std::cout << "Original message: " << message << "\n";
    std::cout << "Numeric representation: ";

    for (int number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n";

    std::string recovered = numbersToText(numbers);
    std::cout << "Recovered message: " << recovered << "\n";

    if (recovered == message) {
        std::cout << "[PASS] Text encoding and decoding\n";
        return 0;
    }

    std::cout << "[FAIL] Text encoding and decoding\n";
    return 1;
}    
