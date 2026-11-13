#include <iostream>
#include "extended_euclidean.hpp"

bool testCoprimeNumbers() {
    ExtendedGCDResult result = extendedGCD(17, 5);

    return result.gcd == 1 &&
           17 * result.x + 5 * result.y == result.gcd;
}

bool testNonCoprimeNumbers() {
    ExtendedGCDResult result = extendedGCD(48, 18);

    return result.gcd == 6 &&
           48 * result.x + 18 * result.y == result.gcd;
}

bool testOneNumberIsZero() {
    ExtendedGCDResult result = extendedGCD(10, 0);

    return result.gcd == 10 &&
           10 * result.x == result.gcd;
}

int main() {
    int passed = 0;
    int failed = 0;

    if (testCoprimeNumbers()) {
        std::cout << "[PASS] Coprime numbers\n";
        ++passed;
    } else {
        std::cout << "[FAIL] Coprime numbers\n";
        ++failed;
    }

    if (testNonCoprimeNumbers()) {
        std::cout << "[PASS] Non-coprime numbers\n";
        ++passed;
    } else {
        std::cout << "[FAIL] Non-coprime numbers\n";
        ++failed;
    }

    if (testOneNumberIsZero()) {
        std::cout << "[PASS] One number is zero\n";
        ++passed;
    } else {
        std::cout << "[FAIL] One number is zero\n";
        ++failed;
    }

    std::cout << "\nPassed: " << passed
              << " | Failed: " << failed << '\n';

    return failed == 0 ? 0 : 1;
}
