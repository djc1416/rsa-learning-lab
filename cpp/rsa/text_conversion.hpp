#pragma once

#include <string>
#include <vector>
#include <stdexcept>

inline std::vector<long long> textToNumbers(
    const std::string& text
) {
    std::vector<long long> numbers;

    for (unsigned char character : text) {
        numbers.push_back(
            static_cast<long long>(character)
        );
    }

    return numbers;
}

inline std::string numbersToText(
    const std::vector<long long>& numbers
) {
    std::string text;

    for (long long number : numbers) {
        if (number < 0 || number > 255) {
            throw std::invalid_argument(
                "Number must represent a valid byte (0-255)."
            );
        }

        text.push_back(
            static_cast<char>(number)
        );
    }

    return text;
}
