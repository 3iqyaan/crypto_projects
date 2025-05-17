## Crypt-Math Library

A C++ library implementing common number theory functions used in cryptography:

- **gcd**: Euclid’s algorithm for greatest common divisor
- **extended_gcd**: Extended Euclid’s algorithm (finds x, y for Bézout’s identity)
- **mod_inverse**: Modular inverse using Extended Euclid
- **phi**: Euler’s Totient function
- **crt**: Chinese Remainder Theorem solver

Includes a simple interactive CLI using GNU Readline for easy testing.

---

## Project Structure

CryptMath/
│
├── include/ 
│ └── crypt_math.hpp
│
├── src/ 
│ └── crypt_math.cpp
│
├── cli/
│ └── libtest_cli.cpp
│
├── CMakeLists.txt 
├── README.md 
└── .gitignore 

## Build and Run

```bash
mkdir build
cd build
cmake ..
make
./crypt-math-cli       