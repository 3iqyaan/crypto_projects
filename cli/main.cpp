#include "crypt_math.hpp"
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>
#include <sstream>
#include <vector>

using namespace crypt_math;

// Helper to split input into arguments
std::vector<int> parse_numbers(const std::string& str) {
    std::istringstream iss(str);
    std::vector<int> numbers;
    int n;
    while (iss >> n)
        numbers.push_back(n);
    return numbers;
}

int main() {
    char* input;

    std::cout << "Welcome to CryptMath CLI (type 'help' or 'exit')\n\n";

    while ((input = readline("crypt-math> ")) != nullptr) {
        if (std::string(input).empty()) {
            free(input);
            continue;
        }

        add_history(input);

        std::string cmd(input);
        free(input);

        if (cmd == "exit") break;
        else if (cmd == "help") {
            std::cout << "Commands:\n";
            std::cout << "  gcd a b\n";
            std::cout << "  ext_gcd a b\n";
            std::cout << "  mod_inv a m\n";
            std::cout << "  phi n\n";
            std::cout << "  crt m1 m2 m3 ... | r1 r2 r3 ...\n";
            continue;
        }

        // Parse the command and arguments
        std::istringstream iss(cmd);
        std::string function;
        iss >> function;

        if (function == "gcd") {
            int a, b;
            iss >> a >> b;
            std::cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << "\n\n";
        }
        else if (function == "ext_gcd") {
            int a, b, x, y;
            iss >> a >> b;
            int d = ext_gcd(a, b, x, y);
            std::cout << "extended_gcd(" << a << ", " << b << ") = gcd: " << d << ", x: " << x << ", y: " << y << "\n\n";
        }
        else if (function == "mod_inv") {
            int a, m;
            iss >> a >> m;
            std::cout << "mod_inverse(" << a << ", " << m << ") = " << mod_inv(a, m) << "\n\n";
        }
        else if (function == "phi") {
            int n;
            iss >> n;
            std::cout << "phi(" << n << ") = " << phi(n) << "\n\n";
        }
        else if (function == "crt") {
            std::string mods_str, rems_str;
            std::getline(iss, mods_str, '|');
            std::getline(iss, rems_str);

            auto mods = parse_numbers(mods_str);
            auto rems = parse_numbers(rems_str);

            if (mods.empty() || rems.empty()) {
                std::cout << "Invalid format. Usage: crt m1 m2 m3 ... | r1 r2 r3 ...\n\n";
                continue;
            }

            int result = crt(mods, rems);
            std::cout << "CRT result = " << result << "\n\n";
        }
        else {
            std::cout << "Unknown command. Type 'help' for commands.\n\n";
        }
    }

    std::cout << "Goodbye!\n\n";
    return 0;
}
