#include <iostream>
#include <stdexcept>

#include "rsa_keys.hpp"
#include "../modular_exponentiation.hpp"

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
    // Prime number tests
    check("Prime number 61", isPrime(61), 1);
    check("Composite number 60", isPrime(60), 0);

    // Greatest common divisor
    check("GCD of 17 and 3120", gcd(17, 3120), 1);

    // Modular inverse tests
    check("Modular inverse of 17 mod 3120",
          modularInverse(17, 3120), 2753);

    check("Modular inverse of 7 mod 40",
          modularInverse(7, 40), 23);

    checkThrows("Modular inverse does not exist", [] {
        modularInverse(12, 40);
    });

    checkThrows("Invalid modular inverse modulus", [] {
        modularInverse(7, 1);
    });

    // RSA key generation
    RSAKeys keys = generateRSAKeys(61, 53, 17);

    check("RSA modulus n", keys.n, 3233);
    check("Euler totient phi(n)", keys.phi, 3120);
    check("Public exponent e", keys.e, 17);
    check("Private exponent d", keys.d, 2753);

    // RSA encryption and decryption
    long long message = 65;

    long long encrypted = modularExponentiation(
        message, keys.e, keys.n
    );

    long long decrypted = modularExponentiation(
        encrypted, keys.d, keys.n
    );

    check("Encrypted message", encrypted, 2790);
    check("Decrypted message", decrypted, message);

    // Invalid RSA key generation tests
    checkThrows("Non-prime p", [] {
        generateRSAKeys(60, 53, 17);
    });

    checkThrows("Repeated primes", [] {
        generateRSAKeys(53, 53, 17);
    });

    checkThrows("Invalid public exponent", [] {
        generateRSAKeys(61, 53, 12);
    });

    std::cout << "\nPassed: " << passed
              << " | Failed: " << failed << '\n';

    return failed == 0 ? 0 : 1;
}
