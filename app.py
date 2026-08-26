import streamlit as st

from modules.euclidean_algorithm import gcd
from modules.number_theory import is_prime, euler_totient
from modules.modular_arithmetic import modular_power, modular_power_manual, modular_inverse 
from modules.rsa import generate_keys
from modules.rsa_message import (
    decrypt_text,
    encrypt_text,
    encryption_steps,
    decryption_steps,
)

st.title("RSA Learning Lab")

st.write(
    "An educational implementation of RSA cryptography "
    "built from mathematical foundations."
)    

st.header("Key Generation")

p = st.number_input("Prime p", min_value=2, value=61, step=1)
q = st.number_input("Prime q", min_value=2, value=53, step=1)
e = st.number_input("Public exponent e", min_value=2, value=17, step=1)

if "public_key" not in st.session_state:
    st.session_state.public_key = None

if "private_key" not in st.session_state:
    st.session_state.private_key = None

if "ciphertext" not in st.session_state:
    st.session_state.ciphertext = None

if st.button("Generate Keys"):
    try:
        public_key, private_key = generate_keys(p, q, e)

        st.session_state.public_key = public_key
        st.session_state.private_key = private_key
        st.session_state.ciphertext = None

        n = p * q
        phi = (p - 1) * (q - 1)
        d = private_key[1]

        st.success("Keys generated successfully!")
        st.subheader("RSA Mathematics")

        st.write("1. Calculate n:")
        st.latex(rf"n = p \times q = {p} \times {q} = {n}")

        st.write("2. Calculate φ(n):")
        st.latex(
            rf"\phi(n) = (p - 1) (q -1) = "
            rf"({p} - 1) ({q} - 1) = {phi}"
        )

        st.write("3. Public exponent:")
        st.latex(rf"e = {e}")

        st.write("4. Calculate the private exponent d:")
        st.latex(
            rf"d = e^{{-1}} \mod \phi(n) = "
            rf"{e}^{{-1}} \mod {phi} = {d}"
        )
        st.write("Public Key:", public_key)
        st.write("Private Key:", private_key)

    except ValueError as error:
        st.error(str(error))


if st.session_state.public_key is not None:
    st.write("Public Key:", st.session_state.public_key)
    st.write("Private Key:", st.session_state.private_key)

    st.header("Encryption")

    message = st.text_input("Message", value="HELLO")

    if st.button("Encrypt"):
        try:
            ciphertext = encrypt_text(
                message,
                st.session_state.public_key
            )

            st.session_state.ciphertext = ciphertext

            st.success("Message encrypted successfully!")
            st.write("Ciphertext:", ciphertext)

            st.subheader("Encryption Steps")

            steps = encryption_steps(
                message,
                st.session_state.public_key
            )

            for step in steps:
                st.write(f"**{step['char']} → {step['number']}**")
                st.latex(
                    rf"{step['number']} ^{{e}} \mod n = {step['ciphertext']}"
                )

        except ValueError as error:
            st.error(str(error))

    if st.session_state.ciphertext is not None:
        st.header("Decryption")

        if st.button("Decrypt"):
            decrypted = decrypt_text(
                st.session_state.ciphertext,
                st.session_state.private_key
            )

            st.success("Message decrypted successfully!")
            st.write("Recovered message:", decrypted)    

            st.subheader("Decryption Steps")
            steps = decryption_steps(
                st.session_state.ciphertext,
                st.session_state.private_key
            )

            n, d = st.session_state.private_key

            for step in steps:
                st.write(f"**{step['ciphertext']} → {step['number']}**")
                st.latex(
                    rf"{step['ciphertext']} ^{{d}} \mod n = "
                    rf"{step['number']}"
                )

st.header("Mathematical Foundations")

st.subheader("Prime Numbers")

st.write(
        "RSA relies on prime numbers. A prime number is an integer greater "
        "than 1 that has exactly two positive divisors: 1 and itself. " 
          )   

prime_input = st.number_input(
        "Enter a number to test",
        min_value=1,
        value=17,
        step=1,
)

if "prime_result" not in st.session_state:
    st.session_state.prime_result = None

if "prime_number" not in st.session_state:
    st.session_state.prime_number = None

if st.button("Check Prime"):
    st.session_state.prime_number = prime_input
    st.session_state.prime_result = is_prime(prime_input)

if st.session_state.prime_result is not None:
    if st.session_state.prime_result:
        st.success(
            f"{st.session_state.prime_number} is prime."
        )
    else:
        st.warning(
            f"{st.session_state.prime_number} is not prime."
        )


st.subheader("Modular Arithmetic")

st.write(
    "Modular arithmetic works with remainders. "
    "RSA uses modular exponentiation during encryption and decryption. "
)

base = st.number_input(
    "Base",
    min_value=0,
    value=72,
    step=1,
)

exponent = st.number_input(
    "Exponent",
    min_value=0,
    value=17,
    step=1,
)

modulus = st.number_input(
    "Modulus",  
    min_value=1,
    value=3233,
    step=1,
)

if st.button("Calculate Modular Power"):
    result = modular_power(base, exponent, modulus)

    st.success("Calculation completed")

    st.latex(
        rf"{base}^{{exponent}} \mod {modulus} = {result}"        
    )

st.subheader("GCD / Euclidean Algorithm")

st.write(
    "The Euclidean Algorithm calculates the greatest common divisor "
    "(GCD) of two integers."
)

a = st.number_input(
    "First number",
    min_value=0,
    value=48,
    step=1,
)

b = st.number_input(
    "Second number",
    min_value=0,
    value=12,
    step=1,
)

if st.button("Calculate GCD"):
    result = gcd(a, b)

    st.success("GCD calculated successfully")

    st.latex(
        rf"\gcd({a}, {b}) = {result}"
    )


st.subheader("Modular Inverse")

st.write(
    "The modular inverse of a number is a value that produces " 
    "a remainder of 1 when multiplied by the original number. "
)

a = st.number_input(
    "Number a",
    min_value=1,
    value=17,
    step=1,
    key="inverse_a",
)

m = st.number_input(
    "Modulus m",
    min_value=2,
    value=3120,
    step=1,
    key="inverse_m",
)

if st.button("Calculate Modular Inverse"):
    try:
        result = modular_inverse(a, m)

        st.success("Modular inverse calculated successfully")

        st.latex(
            rf"{a}^{{-1}} \mod {m} = {result}"
        )

        st.latex(
            rf"{a} \times {result} \equiv 1 \pmod{{m}}"
        )

    except ValueError as error:
        st.error(str(error))   

st.subheader("Euler's Totient Function")

st.write(
    "Euler's Totient Function counts the positive integers up to n "
    "that are relatively prime to n."
)

n_input = st.number_input(
    "Enter n",
    min_value=1,
    value=3233,
    step=1,
    key="totient_n",
)

if st.button("Calculate Euler's Totient"):
    result= euler_totient(n_input)

    st.success("Euler's Totient calculated successfully")

    st.latex(
        rf"\phi({n_input}) = {result}"
    )

st.subheader("RSA Connection")

st.write(
    "RSA combines prime numbers, Euler's Totient function, "
    "the GCD, and the modular inverse to generate its keys."
)

rsa_p = st.number_input(
    "Prime p",
    min_value=2,
    value=61,
    step=1,
    key="rsa_connection_p",
)

rsa_q = st.number_input(
    "Prime q",
    min_value=2,
    value=53,
    step=1,
    key="rsa_connection_q",
)

rsa_e = st.number_input(
    "Public exponent e",
    min_value=2,
    value=17,
    step=1,
    key="rsa_connection_e",
)

if st.button("Show RSA Mathematical connection"):
    try:
        n = rsa_p * rsa_q
        phi = euler_totient(n)
        d = modular_inverse(rsa_e, phi)
        gcd_result = gcd(rsa_e, phi)

        st.success("RSA mathematical connection calculated")

        st.write("1. Calculate n:")
        st.latex(
            rf"n = p \times q = {rsa_p} \times {rsa_q} = {n}"
        )

        st.write("2. Calculate Euler's totient:")
        st.latex(
            rf"\phi(n) = \phi({n}) = {phi}"
        )

        st.write("3. Verify the public exponent:")
        st.latex(
            rf"\gcd({rsa_e}, {phi}) = {gcd_result}"
        )

        st.write("4. Calculate the private exponent:")
        st.latex(
            rf"d = {rsa_e}^{{-1}} \mod {phi} = {d}"
        )

        st.write("5. Keys:")
        st.latex(
            rf"\text{{Public Key}} = ({n}, {rsa_e})"
        )
        st.latex(
            rf"\text{{Private Key}} = ({n}, {d})"
        )
    except ValueError as error:
        st.error(str(error))      