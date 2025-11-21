# Encrypter-Decrypter
This is a simple mini project in c++ for encrypting/decrypting passowrd and generating strong password. The encryption/decryption is inspired from the classic "Ceasar Cipher" implementations. 
## How it Works
Encryption:
Each character (A-Z, a-z, 0-9) is shifted by a fixed amount (default = 7, but you can change it). Special characters don’t change.
For digits, the function can handle different shifts if you want, making it slightly more interesting.

Decryption:
Opposite of encryption, same logic. Give the encrypted password and get back the original.

Password Generation:
You can set the total length, number of digits, and number of symbols in the generated password. Super handy if you keep forgetting passwords or need one for some signup.

## How to Use
Just compile and run, you'll see a menu like this: <br/>
<img width="188" height="90" alt="image" src="https://github.com/user-attachments/assets/c1c9bfc5-8d25-4a17-9365-fee5964003a3" />
