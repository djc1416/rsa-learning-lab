#pragma once

#include <stdexcept>
#include "extended_euclidean.hpp"

struct RSAKeys {
    long long p;
    long long q;
    long long n;
    long long phi;
    long long e;
    long long d;
};


inline bool isPrime(long long number) {
    if (number < 2) {
        return false;
    }

    for (long long i = 2; i <= number / i; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}


inline long long gcd(long long a, long long b) {
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}


inline long long modularInverse(long long a, long long modulus) {
    if (modulus <= 1) {
        throw std::invalid_argument(
            "Modulus must be greater than 1."
        );
    }

    ExtendedGCDResult result = extendedGCD(a, modulus);

    if (result.gcd != 1) {
        throw std::invalid_argument(
            "Modular inverse does not exist."
        );
    }

    long long inverse = result.x % modulus;

    if (inverse < 0) {
        inverse += modulus;
    }

    return inverse;
}


inline RSAKeys generateRSAKeys(
    long long p,
    long long q,
    long long e
) {
    if (!isPrime(p) || !isPrime(q)) {
        throw std::invalid_argument(
            "Both p and q must be prime numbers."
        );
    }

    if (p == q) {
        throw std::invalid_argument(
            "p and q must be different primes."
        );
    }

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    if (e <= 1 || e >= phi) {
        throw std::invalid_argument(
            "Public exponent e must be between 1 and phi(n)."
        );
    }

    if (gcd(e, phi) != 1) {
        throw std::invalid_argument(
            "Public exponent e must be coprime with phi(n)."
        );
    }

    long long d = modularInverse(e, phi);

    return {p, q, n, phi, e, d};
}
