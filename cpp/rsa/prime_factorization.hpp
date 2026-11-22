#pragma once

#include <vector>
#include <stdexcept>

inline std::vector<long long> findPrimeFactors(long long n) {
    if (n <= 0) {
        throw std::invalid_argument(
            "Input must be a positive integer."
        );
    }

    std::vector<long long> factors;

    for (long long p = 2; p <= n / p; ++p) {
        if (n % p == 0) {
            factors.push_back(p);

            while (n % p == 0) {
                n /= p;
            }
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}
