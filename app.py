import streamlit as st

from modules.rsa import generate_keys
from modules.rsa_message import decrypt_text, encrypt_text

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