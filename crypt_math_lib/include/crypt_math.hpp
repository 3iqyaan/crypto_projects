#pragma once
#include <span>

namespace crypt_math {

    // Greatest common divisor using euclid's algorithm
    int gcd(int a, int b);

    // Extended euclidean algorithm, returns gcd(a,b), finds x,y for
    // a*x + b*y = gcd(a,b)
    int ext_gcd(int a, int b, int& x, int& y);

    // Returns the coefficient of a to make it congruent to 1 mod m
    int mod_inv(int a, int m);

    // Eulers Totient function
    int phi(int n);

    // Chinese remainder theorem
    int crt(std::span <const int> mods, std::span <const int> rems);
}