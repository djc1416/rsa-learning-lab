#include <iostream>
#include <stdexcept>
#include "rsa_encryption.hpp"

int main() {
    int passed = 0;
    int failed = 0;

    auto runTest = [&](const std::string& name,
                       long long actual,
                       long long expected) {
        if (actual == expected) {
            std::cout << "[PASS] " << name << '\n';
            ++passed;
        } else {
            std::cout << "[FAIL] " << name
                      << " | Expected: " << expected
                      << " | Actual: " << actual << '\n';
            ++failed;
        }
    };

    auto runInvalidInputTest = [&](const std::string& name,
                                   long long message,
                                   long long exponent,
                                   long long modulus) {
        try {
            rsaEncrypt(message, exponent, modulus);
            std::cout << "[FAIL] " << name << '\n';
            ++failed;
        } catch (const std::invalid_argument&) {
            std::cout << "[PASS] " << name << '\n';
            ++passed;
        }
    };

    runTest(
        "RSA encryption of message 65",
        rsaEncrypt(65, 17, 3233),
        2790
    );

    runTest(
        "Encryption of zero",
        rsaEncrypt(0, 17, 3233),
        0
    );

    runTest(
        "Encryption with message 1",
        rsaEncrypt(1, 17, 3233),
        1
    );

    runTest(
        "Encryption with message n - 1",
        rsaEncrypt(3232, 17, 3233),
        3232
    );

    runInvalidInputTest(
        "Reject negative message",
        -1, 17, 3233
    );

    runInvalidInputTest(
        "Reject message equal to modulus",
        3233, 17, 3233
    );

    runInvalidInputTest(
        "Reject message greater than modulus",
        3234, 17, 3233
    );

    runInvalidInputTest(
        "Reject zero public exponent",
        65, 0, 3233
    );

    runInvalidInputTest(
        "Reject negative public exponent",
        65, -17, 3233
    );

    runInvalidInputTest(
        "Reject invalid modulus",
        65, 17, 1
    );

    std::cout << "\n============================\n";
    std::cout << "RSA Encryption Tests\n";
    std::cout << "Passed: " << passed << '\n';
    std::cout << "Failed: " << failed << '\n';
    std::cout << "============================\n";

    return failed == 0 ? 0 : 1;
}
