#pragma once

#include <stdexcept>
#include "../modular_exponentiation.hpp"

inline long long rsaDecrypt(
    long long ciphertext,
    long long privateExponent,
    long long modulus
) {
    if (modulus <= 1) {
        throw std::invalid_argument(
            "RSA modulus must be greater than 1."
        );
    }

    if (privateExponent <= 0) {
        throw std::invalid_argument(
            "Private exponent must be positive."
        );
    }

    if (ciphertext < 0 || ciphertext >= modulus) {
        throw std::invalid_argument(
            "Ciphertext must be between 0 and modulus - 1."
        );
    }

    return modularExponentiation(
        ciphertext,
        privateExponent,
        modulus
    );
}
