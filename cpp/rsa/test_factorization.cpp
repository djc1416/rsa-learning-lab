#include <iostream>
#include "factorization.hpp"

int main() {
    int passed = 0;
    int failed = 0;

    FactorizationResult result = factorize(3233);

    if (result.found &&
        result.factor1 == 53 &&
        result.factor2 == 61) {

        std::cout << "[PASS] Factorization of 3233\n";
        ++passed;
    } else {
        std::cout << "[FAIL] Factorization of 3233\n";
        ++failed;
    }

    std::vector<long long> testedDivisors;
    FactorizationResult trackingResult = factorize(3233, &testedDivisors);

    if (trackingResult.found &&
        testedDivisors.size() == 52 &&
        testedDivisors.front() == 2 &&
        testedDivisors.back() == 53) {

        std::cout << "[PASS] Divisor tracking\n";
        ++passed;
    } else {
        std::cout << "[FAIL] Divisor tracking\n";
        ++failed;
    }

    FactorizationResult primeResult = factorize(61);

    if (!primeResult.found) {
        std::cout << "[PASS] Prime number detection\n";
        ++passed;
    } else {
        std::cout << "[FAIL] Prime number detection\n";
        ++failed;
    }

    FactorizationResult invalidResult = factorize(1);

    if (!invalidResult.found) {
        std::cout << "[PASS] Invalid input handling\n";
        ++passed;
    } else {
        std::cout << "[FAIL] Invalid input handling\n";
        ++failed;
    }

    std::cout << "\nPassed: " << passed
              << " | Failed: " << failed << "\n";

    return failed == 0 ? 0 : 1;
}
