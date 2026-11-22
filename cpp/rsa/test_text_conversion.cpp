#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "text_conversion.hpp"

int main() {
    int passed = 0;
    int failed = 0;

    auto runTest = [&](const std::string& name,
                       const std::vector<long long>& actual,
                       const std::vector<long long>& expected) {
        if (actual == expected) {
            std::cout << "[PASS] " << name << '\n';
            ++passed;
        } else {
            std::cout << "[FAIL] " << name << '\n';
            ++failed;
        }
    };

    auto runTextTest = [&](const std::string& name,
                           const std::string& actual,
                           const std::string& expected) {
        if (actual == expected) {
            std::cout << "[PASS] " << name << '\n';
            ++passed;
        } else {
            std::cout << "[FAIL] " << name << '\n';
            ++failed;
        }
    };

    auto runInvalidInputTest = [&](const std::string& name,
                                   const std::vector<long long>& numbers) {
        try {
            numbersToText(numbers);
            std::cout << "[FAIL] " << name << '\n';
            ++failed;
        } catch (const std::invalid_argument&) {
            std::cout << "[PASS] " << name << '\n';
            ++passed;
        }
    };

    runTest(
        "Convert HELLO to ASCII numbers",
        textToNumbers("HELLO"),
        {72, 69, 76, 76, 79}
    );

    runTextTest(
        "Recover HELLO from ASCII numbers",
        numbersToText({72, 69, 76, 76, 79}),
        "HELLO"
    );

    runTest(
        "Convert an empty string",
        textToNumbers(""),
        {}
    );

    runTextTest(
        "Recover an empty string",
        numbersToText({}),
        ""
    );

    runTest(
        "Convert lowercase text",
        textToNumbers("rsa"),
        {114, 115, 97}
    );

    runTest(
        "Convert text containing spaces",
        textToNumbers("RSA LAB"),
        {82, 83, 65, 32, 76, 65, 66}
    );

    runTextTest(
        "Recover text containing spaces",
        numbersToText({82, 83, 65, 32, 76, 65, 66}),
        "RSA LAB"
    );

    runInvalidInputTest(
        "Reject negative byte value",
        {-1}
    );

    runInvalidInputTest(
        "Reject byte value greater than 255",
        {256}
    );

    std::cout << "\n============================\n";
    std::cout << "Text Conversion Tests\n";
    std::cout << "Passed: " << passed << '\n';
    std::cout << "Failed: " << failed << '\n';
    std::cout << "============================\n";

    return failed == 0 ? 0 : 1;
}
