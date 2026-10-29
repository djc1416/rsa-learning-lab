#pragma once 

#include <stdexcept>

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
            result = (result * base) % modulus;
        }
        exponent /= 2;
        base = (base * base) % modulus;
    }
    return result;
}