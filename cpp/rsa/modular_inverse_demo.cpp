#include <iostream>
#include <stdexcept>
#include "extended_euclidean.hpp"

int main() {
    long long a;
    long long modulus;

    std::cout << "=== Modular Inverse Demonstration ===\n\n";

    std::cout << "Enter a number (a): ";
    if (!(std::cin >> a)) {
        std::cerr << "Error: Invalid number input.\n";
        return 1;
    }

    std::cout << "Enter the modulus: ";
    if (!(std::cin >> modulus)) {
        std::cerr << "Error: Invalid modulus input.\n";
        return 1;
    }

    if (modulus <= 1) {
        std::cerr << "Error: Modulus must be greater than 1.\n";
        return 1;
    }

    ExtendedGCDResult result = extendedGCD(a, modulus);

    std::cout << "\n=== Extended Euclidean Algorithm ===\n";
    std::cout << "GCD: " << result.gcd << '\n';
    std::cout << "Bézout coefficient x: " << result.x << '\n';
    std::cout << "Bézout coefficient y: " << result.y << '\n';

    std::cout << "\nBézout identity:\n";
    std::cout << a << " * (" << result.x << ") + "
              << modulus << " * (" << result.y << ") = "
              << result.gcd << '\n';

    if (result.gcd != 1) {
        std::cout << "\nNo modular inverse exists because "
                  << "gcd(a, modulus) is not 1.\n";
        return 0;
    }

    long long inverse = result.x % modulus;

    if (inverse < 0) {
        inverse += modulus;
    }

    std::cout << "\n=== Modular Inverse ===\n";
    std::cout << "Modular inverse: " << inverse << '\n';

    std::cout << "Verification: ("
              << a << " * " << inverse
              << ") mod " << modulus << " = "
              << (a * inverse) % modulus << '\n';

    return 0;
}
