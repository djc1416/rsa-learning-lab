#include <iostream>
#include "extended_euclidean.hpp"

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

void testModularInverse17Mod40() {
    ExtendedGCDResult result = extendedGCD(17, 40);

    long long inverse = result.x % 40;

    if (inverse < 0) {
        inverse += 40;
    }

    check(
        "Inverse of 17 mod 40",
        result.gcd == 1 &&
        inverse == 33 &&
        (17 * inverse) % 40 == 1
    );
}

void testModularInverse7Mod40() {
    ExtendedGCDResult result = extendedGCD(7, 40);

    long long inverse = result.x % 40;

    if (inverse < 0) {
        inverse += 40;
    }

    check(
        "Inverse of 7 mod 40",
        result.gcd == 1 &&
        inverse == 23 &&
        (7 * inverse) % 40 == 1
    );
}

void testNoModularInverse() {
    ExtendedGCDResult result = extendedGCD(12, 40);

    check(
        "No inverse for 12 mod 40",
        result.gcd != 1
    );
}

void testBezoutIdentity() {
    ExtendedGCDResult result = extendedGCD(17, 40);

    check(
        "Bezout identity",
        17 * result.x + 40 * result.y == result.gcd
    );
}

void testModularInverseVerification() {
    ExtendedGCDResult result = extendedGCD(17, 40);

    long long inverse = result.x % 40;

    if (inverse < 0) {
        inverse += 40;
    }

    check(
        "Modular inverse verification",
        (17 * inverse) % 40 == 1
    );
}

int main() {
    std::cout << "=== Modular Inverse Tests ===\n\n";

    testModularInverse17Mod40();
    testModularInverse7Mod40();
    testNoModularInverse();
    testBezoutIdentity();
    testModularInverseVerification();

    std::cout << "\nPassed: " << passed
              << " | Failed: " << failed << '\n';

    return failed == 0 ? 0 : 1;
}
