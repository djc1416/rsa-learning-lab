#pragma once
#include <stdexcept>

inline long long eulerTotient(long long n) {
    if (n <= 0) {
        throw std::invalid_argument(
            "Input must be a positive integer."
        );
    }

    long long result = n;
    long long remaining = n;

    for (long long p = 2; p <= remaining / p; ++p) {
        if (remaining % p == 0) {
            while (remaining % p == 0) {
                remaining /= p;
            }

            result = (result / p) * (p - 1);
        }
    }

    if (remaining > 1) {
        result = (result / remaining) * (remaining - 1);
    }

    return result;
}
