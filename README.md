# RSA Learing lab

RSA Learning lab is an interactive educational project that explains how public-key cryptography works through mathematics, visualization, and Python implementations.

## Goal

The goal of this project is to understand the mathematical foundations behind RSA and transform those concepts into working Python implementations.

## What You Will learn

- Prime numbers
- Modular arithmetic
- Greatest Common Divisor
- Euclidean Algorithm
- Euler's Totient Function
- Modular Inverses
- RSA key generation
- Encryption
- Decryption

## Mathematical Foundations

RSA is based on several concepts from number theory and modular arithmetic.
This project implements these concepts from scratch to make the mathematical
foundations behind RSA easier to understand.

### Prime Numbers

A prime number is an integer greater than 1 that has exactly two positive
divisors: 1 and itself.

Examples of prime numbers:

- 2
- 3
- 5
- 7
- 11
- 13

RSA uses two prime numbers, usually represented as `p` and `q`, to construct the modulus:

\[
n = p \times q    
\]

In this project, an exmaple key generation uses:

\[
p = 61, \quad q = 53
\]

Therefore:
\[
n = 61 \times 53 = 3233    
\]

The implementation includes a primality test to determine whether a number
is prime.



## Project Status

In development

## Roadmap

The project will be developed step by step, starting with the mathematical foundations and gradully building a complete educational RSA implementation.