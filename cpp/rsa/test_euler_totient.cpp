#include <iostream>
#include <stdexcept>
#include "euler_totient.hpp"

int passed = 0;
int failed = 0;

void check(const char* name, bool condition) {
    if (condition) {
        std::cout << "[PASS] " << name << '\n';
        ++passed;
    } else {
        std::cout << "[FAIL] " << name << '\n';
        ++failed;
    }
}

void testTotientOfOne() {
    check("Totient of 1", eulerTotient(1) == 1);
}

void testTotientOfPrime() {
    check("Totient of prime 7", eulerTotient(7) == 6);
}

void testTotientOfPrimePower() {
    check("Totient of 16", eulerTotient(16) == 8);
}

void testTotientOfComposite() {
    check("Totient of 10", eulerTotient(10) == 4);
}

void testTotientOfTwoDistinctPrimes() {
    check("Totient of 15", eulerTotient(15) == 8);
}

void testTotientOfRSAExample() {
    check("Totient of RSA modulus 3233",
          eulerTotient(3233) == 3120);
}

void testTotientOfLargePrime() {
    check("Totient of 997",
          eulerTotient(997) == 996);
}

void testInvalidInput() {
    bool exceptionThrown = false;

    try {
        eulerTotient(0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    check("Reject zero input", exceptionThrown);
}

void testNegativeInput() {
    bool exceptionThrown = false;

    try {
        eulerTotient(-10);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    check("Reject negative input", exceptionThrown);
}

int main() {
    std::cout << "=== Euler Totient Tests ===\n\n";

    testTotientOfOne();
    testTotientOfPrime();
    testTotientOfPrimePower();
    testTotientOfComposite();
    testTotientOfTwoDistinctPrimes();
    testTotientOfRSAExample();
    testTotientOfLargePrime();
    testInvalidInput();
    testNegativeInput();

    std::cout << "\nPassed: " << passed
              << " | Failed: " << failed << '\n';

    return failed == 0 ? 0 : 1;
}
