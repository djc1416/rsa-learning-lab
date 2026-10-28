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