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

- `include/` – Contains the header file `crypt_math.hpp` with all function declarations.
- `src/` – Source file `crypt_math.cpp` with implementations of the library functions.
- `cli/` – Command-line interface (`main.cpp`) built using GNU Readline.
- `CMakeLists.txt` – Build configuration for CMake.
- `build/` – Directory where compiled objects and executables are generated (ignored in Git).
- `README.md` – Project documentation.


## Build and Run

```bash
mkdir build
cd build
cmake ..
make
./crypt-math-cli
```

##  System Requirements

- **C++ Compiler**: GCC 10+ or Clang 12+ with support for C++20 (to use span in implementation of Chinese Remainder Theorem)
- **CMake**: Version 3.16 or newer  
- **GNU Readline Library**: For building the CLI (install via package manager)

    
