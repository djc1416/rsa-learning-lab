
#pragma once

#include <stdexcept>

inline long long modularMultiplication(
    long long a,
    long long b,
    long long modulus
) {
    if (modulus <= 0) {
        throw std::invalid_argument("Modulus must be positive.");
    }

    a %= modulus;
    b %= modulus;

    if (a < 0) a += modulus;
    if (b < 0) b += modulus;

    long long result = 0;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result >= modulus - a)
                ? result - (modulus - a)
                : result + a;
        }

        b /= 2;

        if (b > 0) {
            a = (a >= modulus - a)
                ? a - (modulus - a)
                : a + a;
        }
    }

    return result;
}

inline long long modularExponentiation(
    long long base,
    long long exponent,
    long long modulus
) {
    if (modulus <= 0) {
        throw std::invalid_argument("Modulus must be positive.");
    }

    if (exponent < 0) {
        throw std::invalid_argument("Exponent cannot be negative.");
    }

    base %= modulus;

    if (base < 0) {
        base += modulus;
    }

    long long result = 1 % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = modularMultiplication(result, base, modulus);
        }

        exponent /= 2;
        base = modularMultiplication(base, base, modulus);
    }

    return result;
}
