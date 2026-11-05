#include <iostream>
#include <chrono>
#include "factorization.hpp"

int main() {
    const long long numbers[] = {
        3233,
        10403,
        100003,
        1000003,
        1000033
    };

    const int repetitions = 1000;

    volatile long long benchmarkChecksum = 0;

    std::cout << "RSA Learning Lab - Factorization Analysis\n";
    std::cout << "Repetitions: " << repetitions << "\n\n";

    for (long long number : numbers) {

        
        factorize(number);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < repetitions; ++i) {

            long long input = number + (i % 2);

            FactorizationResult result = factorize(input);

            benchmarkChecksum =
                benchmarkChecksum + result.attempts;
        }

        auto end = std::chrono::steady_clock::now();

        auto totalTime =
            std::chrono::duration_cast<std::chrono::nanoseconds>(
                end - start
            ).count();

        double averageTime =
            static_cast<double>(totalTime) / repetitions;

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
        std::cout << "Average execution time: "
                  << averageTime << " nanoseconds\n";

        std::cout << "-----------------------------\n";
    }

    std::cout << "Benchmark checksum: "
              << benchmarkChecksum << "\n";

    return 0;
}
