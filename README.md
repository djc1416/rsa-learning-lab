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

$$
n = p \times q    
$$

In this project, an exmaple key generation uses:

$$
p = 61, \quad q = 53
$$

Therefore:

$$
n = 61 \times 53 = 3233    
$$

The implementation includes a primality test to determine whether a number
is prime.



### Modular Arithmetic

Modular arithmetic is a system of arithmetic based on the remainder
after division.

For example:

$$
17 \mod 5 = 2
$$

This means that when 17 is divided by 5, the remainder is 2.

RSA relies heavily on modular arithmetic. During encryption, a message
is transformed using modular exponentiation:

$$
c = m^e \mod n
$$

where:

- `m` is the numerical representation of the message.
- `e` is the public exponent.
- `n` is the RSA modulus.
- `c` is the resulting ciphertext.

This project implements modular exponentiation to demostrate how
these calculations are performed during RSA encryption.


### Congruences

A congruence describes when two integers have the same remainder
when divided by the same positive integer.

The notation is:

$$
a \equiv b \pmod{m}
$$

This means that `a` and `b` are congruent modulo `m`.

For example:

$$
17 \equiv 5 \pmod{6}
$$

because both numbers leave a remainder of 5 when divided by 6.

Congruences are an important part of modular arithmetic and are used
to describe the mathematical relationships involved in RSA.


### GCD and Euclidean Algorithm

The greatest common divisor of two integers is the largest
positive integer that divides both numbers.

For example:

$$
\gcd(48,12) = 12
$$

Since the remainder is 0, the GCD is 12.

The euclidean algorithm is important in RSA because the public
exponent `e` must be relatively prime to Euler's totient function:

$$
\gcd(e,\phi(n)) = 1
$$

For the RSA example used in this project:

$$
\gcd(17,3120) = 1
$$

This allows the modular inverse of `e` modulo $\phi(n)$ to exist.


### Modular inverse

The modular inverse of an integer `a` modulo `m` is an integer `d`
such that:

$$
a \times d \equiv 1 \pmod{m}
$$

A modular inverse exists only when `a` and `m` are relatively prime:

$$
\gcd(a,m)=1
$$

For example, in our RSA implementation:

$$
17^{-1} \mod 3120 = 2753
$$

This means:

$$
17 \times 2753 \equiv 1 \pmod{3120}
$$

The modular inverse is essential for RSA because the private exponent
`d` is calculated as the modular inverse of the public exponent `e`:

$$
d = e^{-1} \mod \phi(n)
$$

In this project, the modular inverse is implement from scratch and
tested with both valid and invalid inputs.


### Euler's Totient Function

Euler's totient function, denoted by $\phi(n)$, counts the positive
integers up to `n` that are relatively prime to `n`.

When `p` and `q` are distinct prime numbers, the RSA modulus is:

$$
n = p \times q
$$

and euler's totient function can be calculated as:

$$
\phi(n) = (p-1)(q-1)
$$

For the RSA example used in this project:

$$
n= 61 \times 53 = 3233
$$

Therefore:

$$
\phi(3233) = (61-1)(53-1) = 3120
$$

The value of $\phi(n)$ is used when calculating the private exponent
`d`:

$$
d = e^{-1} \mod \phi(n)
$$

This make Euler's totient function an essential part of the RSA
key generation process.


### Conection to RSA

The mathematical concepts described above are combined during RSA key
generation.

The process can be summarized as follows:

1. Choose two prime numbers `p` and `q`.

2. Calculate the modulus:

$$
n = p \times q
$$

3. Calculate Euler's Totient function:

$$
\phi(n) = (p-1)(q-1)
$$

4. Choose a public exponent `e` such that:

$$
\gcd(e, \phi(n)) = 1
$$

5. Calculate the modular inverse of `e`:

$$
d = e^{-1} \mod \phi(n)
$$

6. Generate the keys:

$$
\text{Public Key} = (n,e)
$$

$$
\text{Private Key}= (n,d)
$$

For the example used in this project:

$$
p=61, \quad q=53
$$

$$
n=3233
$$

$$
\phi(n)=3120
$$

$$
e=17
$$

$$
d=2753
$$

Therefore:

$$
\text{Public Key}=(3233,17)
$$

$$
\text{Private Key}=(3233,2753)
$$

These mathematical foundations are implemented in the project to
demonstrate how RSA works step by step.


## Project Status

The core RSA implementation is functional and includes:

- RSA key generation
- Message encryption and decryption
- Encryption and decryption steps
- Prime numbers testing
- Modular exponentiation
- GCD using the Euclidean algorithm
- Modular inverse
- Euler's totient function
- Interactive mathematical explanations
- Automated tests with pytest

## Roadmap

### Completed

- [x] RSA key generation
- [x] Message encryption and decryption
- [x] Encryption and decryption steps
- [x] Prime number testing
- [x] Modular arithmetic
- [x] GCD and Euclidean Algorithm
- [x] Modular inverse
- [x] Euler's totient function
- [x] Interactive mathematical explanations
- [x] Automated test with pytest
- [x] Mathematical foundations documentation

### Planned

- [ ] Improve the user interface and learning experience
- [ ] Add more detailed explanations for RSA encryption and decryption
- [ ] Expand automated test coverage
- [ ] Add aditional educational examples