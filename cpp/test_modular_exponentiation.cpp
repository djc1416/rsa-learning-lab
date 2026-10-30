
#include <iostream>
#include <stdexcept>
#include "modular_exponentiation.hpp"
#include <limits>

int passed = 0;
int failed = 0;

void check(const char* name, long long actual, long long expected) {
    if (actual == expected) {
        std::cout << "[PASS] " << name << '\n';
        ++passed;
    } else {
        std::cout << "[FAIL] " << name
                  << " | Expected: " << expected
                  << ", got: " << actual << '\n';
        ++failed;
    }
}

template <typename Function>
void checkThrows(const char* name, Function operation) {
    try {
        operation();
        std::cout << "[FAIL] " << name
                  << " | Expected an exception\n";
        ++failed;
    } catch (const std::invalid_argument&) {
        std::cout << "[PASS] " << name << '\n';
        ++passed;
    } catch (...) {
        std::cout << "[FAIL] " << name
                  << " | Unexpected exception type\n";
        ++failed;
    }
}

int main() {
    check("RSA example", modularExponentiation(7, 13, 33), 13);
    check("Even exponent", modularExponentiation(2, 4, 7), 2);
    check("Zero exponent", modularExponentiation(7, 0, 33), 1);
    check("Negative base", modularExponentiation(-2, 3, 5), 2);
    check("Modulus one", modularExponentiation(7, 13, 1), 0);

    checkThrows("Zero modulus", [] {
        modularExponentiation(7, 3, 0);
    });

    checkThrows("Negative modulus", [] {
        modularExponentiation(7, 3, -5);
    });

    checkThrows("Negative exponent", [] {
        modularExponentiation(7, -1, 33);
    });

    const long long maxValue =
        std::numeric_limits<long long>::max();

    check(
        "Large number multiplication",
        modularExponentiation(maxValue -1, maxValue -1, maxValue),
        1
    );

    check(
        "Large number exponentiation",
        modularExponentiation(maxValue -1, 2, maxValue),
        1
    );

    std::cout << "\nPassed: " << passed 
              << " | Failed: " << failed << '\n';
    
    return failed == 0 ? 0 : 1;
}