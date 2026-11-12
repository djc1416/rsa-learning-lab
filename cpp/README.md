# C++ — Modular Exponentiation

This directory contains C++ implementations of mathematical algorithms related to RSA cryptography and number theory.

## 1. Modular Exponentiation

The first implementation, `modular_exponentiation.cpp`, calculates modular exponentiation using the **binary exponentiation algorithm**.

Given three integers \(a\), \(b\), and \(n\), the goal is to calculate:

\[
a^b \bmod n
\]

Instead of computing the entire power \(a^b\), which can become extremely large, the algorithm repeatedly squares the base and reduces intermediate results modulo \(n\).

### Mathematical foundation

The algorithm relies on two properties:

- If the exponent is even, \(a^b = (a^2)^{b/2}\).
- If the exponent is odd, one factor of \(a\) can be extracted before reducing the remaining exponent.

At each iteration, the algorithm checks whether the exponent is odd, updates the result when necessary, squares the base modulo \(n\), and divides the exponent by two.

This reduces the number of iterations from \(O(b)\) to **\(O(\log b)\)**, making it much more efficient than multiplying the base repeatedly.

### Example

For the inputs:

\[
a=7,\quad b=13,\quad n=33
\]

the calculation is:

\[
7^{13} \bmod 33 = 13
\]

The program should therefore display:

```text
RSA Learning Lab - C++
Result: 13
```

## 2. How to compile and run

You need a C++ compiler such as GCC (`g++`) installed on your system.

From the root directory of the repository, run:

```bash
g++ cpp/modular_exponentiation.cpp -o cpp/modular_exponentiation.exe
```

Then execute the program in Windows PowerShell:

```powershell
.\cpp\modular_exponentiation.exe
```

## 3. Connection to RSA

Modular exponentiation is a fundamental operation in RSA. RSA encryption and decryption use expressions of the form:

\[
c = m^e \bmod n
\]

\[
m = c^d \bmod n
\]

where \(m\) represents a message block, \(e\) and \(d\) are the public and private exponents, and \(n\) is the RSA modulus.

This implementation demonstrates the underlying mathematical operation. It is an educational example, not a complete RSA implementation, and it must not be used to protect real data.

## 4. Limitations and future improvements

- Validate the input parameters, including the modulus and exponent.
- Add tests covering different bases, exponents, and moduli.
- Address integer overflow when working with larger values.
- Explore how modular exponentiation is used in RSA encryption and decryption.

The goal is to build a clear understanding of the mathematical foundations before extending the implementation further.

## 5. Automated tests

The test suite is implemented in `test_modular_exponentiation.cpp` using standard C++ facilities, without external testing libraries.

It checks:

- The original RSA modular exponentiation example.
- Even and zero exponents.
- Negative bases and modulus one.
- Invalid moduli and negative exponents. 

Compile and run the tests from the repository root:

```bash
g++ cpp/test_modular_exponentiation.cpp -o cpp/test_modular_exponentiation.exe
./cpp/test_modular_exponentiation.exe
```

The program exits with status code `0` if all tests pass and `1` if any test fails.


## 6. Overflow-safe modular multiplication

The implementation now includes modular multiplication using the binary double-and-add method.

Instead of calculating the full product of two integers, the algorithm repeatedly doubles and adds values while reducing them modulo the given modulus.

This avoids intermediate multiplication overflow for positive moduli representable by `long long`.

The modular exponentiation algorithm uses this function for its intermediate calculations.

The multiplication algorithm has O(log b) time complexity, while modular exponentiation has O(log e * log n) time complexity.

This implementation remains educational and is not intended for production cryptographic use.


## 7. RSA Key Generation in C++

The `rsa/` directory introduces an educational RSA key generation implementation.

It includes:

- Prime number validation.
- Greatest Common Divisor (Euclidean Algorithm).
- Modular multiplicative inverse (Extended Euclidean Algorithm).
- RSA modulus calculation.
- Euler's totient function.
- Public and private exponent generation.

### Example

Using p = 61, q = 53 and e = 17:

- n = 3233
- phi(n) = 3120
- Public exponent: e = 17
- Private exponent: d = 2753

The implementation also demonstrates encryption and decryption of a numerical message using modular exponentiation.

### Run the tests

From the repository root:

```bash
g++ cpp/rsa/test_rsa_keys.cpp -o cpp/rsa/test_rsa_keys.exe
./cpp/rsa/test_rsa_keys.exe
```

**Security notice:** This is a small-number educational implementation. It is not suitable for protecting real data or production cryptographic applications.

## 8. RSA Factorization and Performance Analysis

The `rsa/` directory also includes an educational factorization algorithm implemented in `factorization.hpp`.

### Factorization algorithm

The implementation uses **trial division** to determine whether an integer is composite or prime.

Starting from 2, the algorithm checks whether each candidate divisor divides the input number without leaving a remainder.

The search continues while:

\[
i \leq \frac{n}{i}
\]

This condition is equivalent to checking divisors up to the square root of the input number, without calculating \(i^2\) directly.

If a divisor is found, the algorithm returns the two factors.Otherwise, the number is classified as prime.

**Time complexity:** The worst-case time complexity is:

\[
O(\sqrt{n})
\]

This is because, in the worst case, the algorithm must check every candidate divisor up to the square root of the input.

### Performance benchmark

The file `factorization_demo.cpp` measures the execution time of the factorization algorithm using `std::chrono::steady_clock`.

The benchmark performs 1,000 repetitions for each input and calculates the average execution time in nanoseconds.

To vary the inputs during the benchmark, each repetition alternates between the original number and the next integer:

- Original input: \(n\)
- Alternate input: \(n+1\)

The program also records the number of divisor candidates tested when factorizing each original input.

### Experimental results

The following measurements were obtained using GCC with the `-O2` optimization flag:

| Input number | Classification | Attempts for original input | Average benchmark time |
|---:|---|---:|---:|
| 3,233 | Composite | 52 | 366 ns |
| 10,403 | Composite | 100 | 742.8 ns |
| 100,003 | Prime | 315 | 2,239.9 ns |
| 1,000,003 | Prime | 999 | 7,202 ns |
| 1,000,033 | Prime | 999 | 7,374.1 ns |

**Note:** The reported execution times correspond to the alternating inputs used during the benchmark, not exclusively to the original number shown in the table. The attempt counts refer to a separate factorization of the original input.

The benchmark checksum was `1235000`, representing the accumulated number of divisor candidates tested across all measured repetitions.

### Analysis

The experiment illustrates how trial division behaves when processing different types and sizes of integers.

- Composite numbers can be factorized as soon as a divisor is found.
- Prime numbers require checking all candidate divisors up to their square root.
- Larger prime numbers generally require more iterations, increasing the computational workload.

Execution times are affected by hardware, compiler optimizations, and system activity. Therefore, these measurements should be interpreted as observations from a specific experiment rather than universal performance values.

### Limitations

This implementation is intended for mathematical and educational exploration.

Trial division becomes computationally expensive for sufficiently large integers. Although it demonstrates the mathematical basis of integer factorization, it does not represent the advanced algorithms used in practical cryptanalysis.

The implementation is not intended for production cryptographic applications or for protecting real data.


## 9. Factorization Trace Demonstration

The project includes an interactive factorization demonstration implemented in `rsa/factorization_trace_demo.cpp`.

This program provides a step-by-step view of the trial division algorithm, showing the candidate divisors examined during the factorization process.

### How it works

The demonstration reuses the factorization algorithm implemented in `factorization.hpp`.

The algorithm records each tested divisor using an optional `std::vector<long long>` parameter. This allows the program to display the internal search process without duplicating the factorization logic.

For each execution, the program:

- Receives an integer from the user.
- Executes the trial division algorithm.
- Records each candidate divisor tested.
- Displays the attempts in sequential order.
- Reports the resulting factors or classifies the input as prime.
- Displays the total number of attempts.

### Example

For the input:

```text
3233
```

The algorithm examines candidate divisors starting from 2 and continues until it finds 53.

The final result is:

\[
3233 = 53 \times 61
\]

The demonstration reports 52 attempts.

### Example output

```text
=== RSA Learning Lab ===
Factorization Trace Demo

Enter a number to factorize: 3233

=== Factorization Process ===
Attempt 1: Testing divisor 2
Attempt 2: Testing divisor 3
...
Attempt 52: Testing divisor 53

=== Factorization Result ===
3233 = 53 x 61
Total attempts: 52
```

### Compilation and execution

From the root directory of the repository, compile the program using GCC:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic cpp/rsa/factorization_trace_demo.cpp -o cpp/rsa/factorization_trace_demo_linux
```

Run the demonstration:

```bash
./cpp/rsa/factorization_trace_demo_linux
```

### Educational purpose

This demonstration makes the trial division process easier to understand by exposing the candidate divisors examined by the algorithm.

It also illustrates why prime numbers require checking all candidate divisors up to their square root, while composite numbers can be factorized as soon as a divisor is found.

This implementation is intended exclusively for educational purposes and is not suitable for production cryptographic applications.
