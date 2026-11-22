#pragma once

#include <stdexcept>
#include "../modular_exponentiation.hpp"

inline long long rsaEncrypt(
    long long message,
    long long publicExponent,
    long long modulus
) {
    if (modulus <= 1) {
        throw std::invalid_argument(
            "RSA modulus must be greater than 1."
        );
    }

    if (publicExponent <= 0) {
        throw std::invalid_argument(
            "Public exponent must be positive."
        );
    }

    if (message < 0 || message >= modulus) {
        throw std::invalid_argument(
            "Message must be between 0 and modulus - 1."
        );
    }

    return modularExponentiation(
        message,
        publicExponent,
        modulus
    );
}
