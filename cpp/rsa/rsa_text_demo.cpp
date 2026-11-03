#include <iostream>
#include <string>
#include <vector>

#include "rsa_keys.hpp"
#include "text_encoding.hpp"
#include "../modular_exponentiation.hpp"

int main() {
    // 1. Generate RSA keys
    RSAKeys keys = generateRSAKeys(61, 53, 17);

    std::cout << "RSA Learning Lab - Text Encryption Demo\n\n";

    std::cout << "Public key: (" << keys.e << ", " << keys.n << ")\n";
    std::cout << "Private key: (" << keys.d << ", " << keys.n << ")\n\n";

    // 2. Original message
    std::string message = "HELLO";

    std::cout << "Original message: " << message << "\n";

    // 3. Convert text into numbers
    std::vector<int> numbers = textToNumbers(message);

    std::cout << "Numeric representation: ";

    for (int number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n\n";

    // 4. Encrypt each number
    std::vector<int> encryptedNumbers;

    std::cout << "Encrypted numbers: ";

    for (int number : numbers) {
        long long encrypted = modularExponentiation(
            number, keys.e, keys.n
        );

        encryptedNumbers.push_back(static_cast<int>(encrypted));
        std::cout << encrypted << " ";
    }

    std::cout << "\n\n";

    // 5. Decrypt each number
    std::vector<int> decryptedNumbers;

    std::cout << "Decrypted numbers: ";

    for (int number : encryptedNumbers) {
        long long decrypted = modularExponentiation(
            number, keys.d, keys.n
        );

        decryptedNumbers.push_back(static_cast<int>(decrypted));
        std::cout << decrypted << " ";
    }

    std::cout << "\n\n";

    // 6. Recover original message
    std::string recoveredMessage = numbersToText(decryptedNumbers);

    std::cout << "Recovered message: " << recoveredMessage << "\n";

    // 7. Verify result
    if (recoveredMessage == message) {
        std::cout << "\n[PASS] RSA text encryption and decryption\n";
        return 0;
    }

    std::cout << "\n[FAIL] RSA text encryption and decryption\n";
    return 1;
}