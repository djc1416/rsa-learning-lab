#include <iostream>
#include <vector>
#include "factorization.hpp"

int main() {
    long long number;

    std::cout << "=== RSA Learning Lab ===\n";
    std::cout << "Factorization Trace Demo\n\n";

    std::cout << "Enter a number to factorize: ";

    if (!(std::cin >> number)) {
        std::cout << "\nInvalid input. Please enter an integer.\n";
        return 1;
    }

    std::vector<long long> testedDivisors;

    FactorizationResult result = factorize(number, &testedDivisors);

    std::cout << "\n=== Factorization Process ===\n";

    for (std::size_t i = 0; i < testedDivisors.size(); ++i) {
        std::cout << "Attempt " << (i + 1)
                  << ": Testing divisor " << testedDivisors[i]
                  << "\n";
    }

    std::cout << "\n=== Factorization Result ===\n";

    if (result.found) {
        std::cout << number << " = "
                  << result.factor1 << " x "
                  << result.factor2 << "\n";

        std::cout << "Total attempts: "
                  << result.attempts << "\n";

    } else if (result.isPrime) {
        std::cout << number << " is a prime number.\n";

        std::cout << "Total attempts: "
                  << result.attempts << "\n";

    } else {
        std::cout << "Invalid input. Enter a number greater than 1.\n";
    }

    return 0;
}
