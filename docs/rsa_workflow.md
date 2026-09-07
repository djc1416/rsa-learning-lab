# RSA Workflow

This document describes the internal workflow used by RSA Learning Lab
to encrypt and decrypt messages.

## 1. Text Encoding

The input message is converted into numerical values.

For example:

```text
HELLO
```

is converted into a sequence of numbers by the text encoding module.

These numerical values are used as the input for RSA encryption.

## 2. Block Validation

Before encryption, the numerical values are validated using
`split_into_blocks()`.

Each value must be smaller than the RSA modulus:

$$
m < n
$$

If a message value is too large for the modulus, the program raises
an error instead of attempting the encryption.

## 3. RSA Encryption

Each valid numerical value is encrypted using the public key:

$$
c = m^e \mod n
$$

where:

- `m` is the numerical message value.
- `e` is the public exponent.
- `n` is the RSA modulus.
- `c` is the ciphertext.

The public key has the form:

$$
(n,e)
$$

## 4. Ciphertext

The encrypted values are stored as a list of ciphertext values.

For example:

```text
[3000, ..., ...]
```

These values can then be used for decryption.

## 5. RSA Decryption

The ciphertext values are decrypted using the private key:

$$
m = c^d \mod n
$$

where:

- `c` is the ciphertext.
- `d` is the private exponent.
- `n` is the RSA modulus.
- `m` is the recovered numerical message value.

The private key has the form:

$$
(n,d)
$$

## 6. Text Decoding

After decryption, the numerical values are converted back into
characters using the text encoding module.

The original message is then recovered.

## Complete Workflow

The complete process can be summarized as:

```
Message
   ↓
text_to_numbers()
   ↓
Numerical Values
   ↓
split_into_blocks()
   ↓
RSA Encryption
   ↓
Ciphertext
   ↓
RSA Decryption
   ↓
Decrypted Numbers
   ↓
numbers_to_text()
   ↓
Original Text
```

This workflow connects the mathematical foundations of RSA with the
actual implementation of the project.