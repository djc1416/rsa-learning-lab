#pragma once

#include <vector>

struct FactorizationResult {
    long long factor1;
    long long factor2;
    long long attempts;
    bool found;
    bool isPrime;
};

inline FactorizationResult factorize(long long number) {
    long long attempts = 0;

    if (number < 2) {
        return {0, 0, attempts, false, false};
    }

    for (long long i = 2; i <= number / i; ++i) {
        ++attempts;

        if (number % i == 0) {
            return {
                i,
                number / i,
                attempts,
                true,
                false
            };
        }
    }

    return {0, 0, attempts, false, true};
}