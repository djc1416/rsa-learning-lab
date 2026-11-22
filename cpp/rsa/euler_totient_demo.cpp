#include <iostream>
#include <vector>
#include <stdexcept>
#include "euler_totient.hpp"
#include "prime_factorization.hpp"

int main() {
    long long n;

    std::cout << "=== Euler Totient Demonstration ===\n\n";
    std::cout << "Enter a positive integer: ";

    if (!(std::cin >> n)) {
        std::cerr << "Error: Invalid input.\n";
        return 1;
    }

    try {
        long long result = eulerTotient(n);
        std::vector<long long> factors = findPrimeFactors(n);

        std::cout << "\nInput number: " << n << '\n';

        std::cout << "Distinct prime factors: ";

        if (factors.empty()) {
            std::cout << "None";
        } else {
            for (std::size_t i = 0; i < factors.size(); ++i) {
                std::cout << factors[i];

                if (i + 1 < factors.size()) {
                    std::cout << ", ";
                }
            }
        }

        std::cout << "\n\nEuler's totient calculation:\n";
        std::cout << "phi(" << n << ") = " << n;

        for (long long factor : factors) {
            std::cout << " * (1 - 1/" << factor << ")";
        }

        std::cout << "\n\nResult: phi(" << n << ") = "
                  << result << '\n';

    } catch (const std::invalid_argument& error) {
        std::cerr << "\nError: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
