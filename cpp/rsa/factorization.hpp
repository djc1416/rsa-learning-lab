#pragma once

#include <vector>

struct FactorizationResult {
    long long factor1;
    long long factor2;
    long long attempts;
    bool found;
};

inline FactorizationResult factorize(long long number) {
    long long attempts = 0;

    if (number < 4) {
        return {0, 0, attempts, false};
    }

    for (long long i = 2; i <= number / i; ++i) {
        ++attempts;

        if (number % i == 0) {
            return {
                i,
                number / i,
                attempts,
                true
            };
        }
    }

    return {0, 0, attempts, false};
}