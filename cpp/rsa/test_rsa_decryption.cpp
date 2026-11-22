#include <iostream>
#include <stdexcept>
#include "rsa_decryption.hpp"

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
                                   long long ciphertext,
                                   long long exponent,
                                   long long modulus) {
        try {
            rsaDecrypt(ciphertext, exponent, modulus);
            std::cout << "[FAIL] " << name << '\n';
            ++failed;
        } catch (const std::invalid_argument&) {
            std::cout << "[PASS] " << name << '\n';
            ++passed;
        }
    };

    runTest(
        "RSA decryption of ciphertext 2790",
        rsaDecrypt(2790, 2753, 3233),
        65
    );

    runTest(
        "Decryption of zero",
        rsaDecrypt(0, 2753, 3233),
        0
    );

    runTest(
        "Decryption of ciphertext 1",
        rsaDecrypt(1, 2753, 3233),
        1
    );

    runTest(
        "Decryption of ciphertext n - 1",
        rsaDecrypt(3232, 2753, 3233),
        3232
    );

    runInvalidInputTest(
        "Reject negative ciphertext",
        -1, 2753, 3233
    );

    runInvalidInputTest(
        "Reject ciphertext equal to modulus",
        3233, 2753, 3233
    );

    runInvalidInputTest(
        "Reject ciphertext greater than modulus",
        3234, 2753, 3233
    );

    runInvalidInputTest(
        "Reject zero private exponent",
        2790, 0, 3233
    );

    runInvalidInputTest(
        "Reject negative private exponent",
        2790, -2753, 3233
    );

    runInvalidInputTest(
        "Reject invalid modulus",
        2790, 2753, 1
    );

    std::cout << "\n============================\n";
    std::cout << "RSA Decryption Tests\n";
    std::cout << "Passed: " << passed << '\n';
    std::cout << "Failed: " << failed << '\n';
    std::cout << "============================\n";

    return failed == 0 ? 0 : 1;
}
