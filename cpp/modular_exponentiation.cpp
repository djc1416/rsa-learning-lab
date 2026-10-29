
#include <iostream>
#include "modular_exponentiation.hpp"

int main() {
    long long base = 7;
    long long exponent = 13;
    long long modulus = 33;

    std::cout << "RSA Learning Lab - C++" << '\n';
    std::cout << "Result: "
              << modularExponentiation(base, exponent, modulus)
              << '\n';

    return 0;
}
