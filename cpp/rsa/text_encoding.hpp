#pragma once

#include <string>
#include <vector>

inline std::vector<int> textToNumbers(const std::string& text) {
    std::vector<int> numbers;
    
    for (unsigned char character : text) {
        numbers.push_back(static_cast<int>(character));
    }

    return numbers;
}

inline std::string numbersToText(const std::vector<int>& numbers) {
    std::string text;
    
    for (int number : numbers) {
        text.push_back(static_cast<char>(number));
    }
    return text;
}
