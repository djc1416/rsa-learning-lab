#include <iostream>

long long modularExponentiation(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent / 2;
        base = (base * base) % modulus;
    }
    return result;
}

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
