#include <iostream>
#include <vector>
#include <stdexcept>
#include "prime_factorization.hpp"

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

    auto runInvalidInputTest = [&](const std::string& name,
                                   long long input) {
        try {
            findPrimeFactors(input);
            std::cout << "[FAIL] " << name << '\n';
            ++failed;
        } catch (const std::invalid_argument&) {
            std::cout << "[PASS] " << name << '\n';
            ++passed;
        }
    };

    runTest(
        "Factorization of 12",
        findPrimeFactors(12),
        {2, 3}
    );

    runTest(
        "Factorization of a prime number",
        findPrimeFactors(13),
        {13}
    );

    runTest(
        "Factorization of 72 without duplicate factors",
        findPrimeFactors(72),
        {2, 3}
    );

    runTest(
        "Factorization of 3233",
        findPrimeFactors(3233),
        {53, 61}
    );

    runTest(
        "Factorization of 1",
        findPrimeFactors(1),
        {}
    );

    runInvalidInputTest(
        "Reject zero",
        0
    );

    runInvalidInputTest(
        "Reject negative input",
        -10
    );

    std::cout << "\n============================\n";
    std::cout << "Tests completed\n";
    std::cout << "Passed: " << passed << '\n';
    std::cout << "Failed: " << failed << '\n';
    std::cout << "============================\n";

    return failed == 0 ? 0 : 1;
}
