#pragma once

#include <stdexcept>

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
        throw std::invalid_argument("Modulus must be greater than 1.");
    }

    long long originalModulus = modulus;
    long long oldR = a;
    long long r = modulus;
    long long oldS = 1;
    long long s = 0;

    while (r != 0) {
        long long quotient = oldR / r;

        long long tempR = oldR - quotient * r;
        oldR = r;
        r = tempR;

        long long tempS = oldS - quotient * s;
        oldS = s;
        s = tempS;
    }

    if (oldR != 1) {
        throw std::invalid_argument(
            "Modular inverse does not exist."
        );
    }

    long long result = oldS % originalModulus;

    if (result < 0) {
        result += originalModulus;
    }

    return result;
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
