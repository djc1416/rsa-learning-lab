
#include <iostream>
#include "factorization.hpp"

int main() {
    long long numbers[] = {
        3233,
        10403,
        100003
    };

    std::cout << "RSA Learning Lab - Factorization Analysis\n\n";

    for (long long number : numbers) {
        FactorizationResult result = factorize(number);

        std::cout << "Number: " << number << "\n";

        if (result.found) {
            std::cout << "Status: Composite\n";
            std::cout << "Factor 1: " << result.factor1 << "\n";
            std::cout << "Factor 2: " << result.factor2 << "\n";
        } else if (result.isPrime) {
            std::cout << "Status: Prime\n";
        } else {
            std::cout << "Status: Invalid input\n";
        }

        std::cout << "Attempts: " << result.attempts << "\n";
        std::cout << "-----------------------------\n";
    }

    return 0;
}
