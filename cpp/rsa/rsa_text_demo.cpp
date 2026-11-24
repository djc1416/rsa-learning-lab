#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "rsa_keys.hpp"
#include "text_conversion.hpp"
#include "rsa_encryption.hpp"
#include "rsa_decryption.hpp"

int main() {
    try {
        // 1. Generate RSA keys
        RSAKeys keys = generateRSAKeys(61, 53, 17);

        std::cout << "RSA Learning Lab - Text Encryption Demo\n\n";

        std::cout << "Public key: ("
                  << keys.e << ", " << keys.n << ")\n";

        std::cout << "Private key: ("
                  << keys.d << ", " << keys.n << ")\n\n";

        // 2. Original message
        const std::string message = "HELLO";

        std::cout << "Original message: "
                  << message << '\n';

        // 3. Convert text into numeric blocks
        std::vector<long long> numbers =
            textToNumbers(message);

        std::cout << "Numeric representation: ";

        for (long long number : numbers) {
            std::cout << number << ' ';
        }

        std::cout << "\n\n";

        // 4. Encrypt each numeric block
        std::vector<long long> encryptedNumbers;

        std::cout << "Encrypted numbers: ";

        for (long long number : numbers) {
            long long encrypted = rsaEncrypt(
                number, keys.e, keys.n
            );

            encryptedNumbers.push_back(encrypted);
            std::cout << encrypted << ' ';
        }

        std::cout << "\n\n";

        // 5. Decrypt each encrypted block
        std::vector<long long> decryptedNumbers;

        std::cout << "Decrypted numbers: ";

        for (long long number : encryptedNumbers) {
            long long decrypted = rsaDecrypt(
                number, keys.d, keys.n
            );

            decryptedNumbers.push_back(decrypted);
            std::cout << decrypted << ' ';
        }

        std::cout << "\n\n";

        // 6. Recover original message
        std::string recoveredMessage =
            numbersToText(decryptedNumbers);

        std::cout << "Recovered message: "
                  << recoveredMessage << '\n';

        // 7. Verify result
        if (recoveredMessage == message) {
            std::cout
                << "\n[PASS] RSA text encryption and decryption\n";

            return 0;
        }

        std::cout
            << "\n[FAIL] RSA text encryption and decryption\n";

        return 1;

    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }
}
