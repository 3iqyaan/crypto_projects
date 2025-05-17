#include "crypt_math.hpp"
#include <iostream>
#include <algorithm>
#include <span>

namespace crypt_math {

    // Euclids algorithm
    // Time complexity - O(log(min(a, b)))
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    // Extended Euclids algorithm
    // Returns gcd,
    // Finds bezout's coefficents x and y
    int ext_gcd(int a, int b, int& x, int& y){

        // base case
        if(b == 0){
            x = 1;
            y = 0;
            return a;
        }

        int x1, y1;
        int gcd = ext_gcd(b, a % b, x1, y1);

        x = y1;
        y = x1 - ((a / b) * y1);

        return gcd;
    }

    // Returns mod inverse of a for mod m 
    // Returns -1 if mod inverse doesn't exist ( i.e, a and m aren't coprime)
    int mod_inv(int a, int m){

        int x, y;
        int gcd = ext_gcd(a, m, x, y);
        if (gcd != 1){
            std::cout << "Modular inverse do not exist, inputs are not coprime";
            return -1;
        }

        // Incase x is negative, or greater than m, we must make it 0 <= x < m 
        x = ((x % m) + m) % m;
        return x;
    }

    // Eulers totient function
    // Counts number coprime with n Between 1 and n
    // Time complexity - O(sqrt(n))
    int phi(int n){

        int phi = n;
        for( int p=2; p*p <= n; p++){
            if( n % p == 0){
                while(n % p == 0){
                    n /= p;
                }
                phi -= phi/p;
            }
        }
        // To account for n becoming a prime number upon division
        if(n > 1) phi -= phi/n; 
        return phi;
    }

    // Chinese remainder theorem
    // Returns -1 incase:
    // - Number of moduli and remainders doesn't match
    // - Moduli aren't pairwise coprime 
    int crt(std::span <const int> mods, std::span <const int> rems){

        int res = 0;
        if(mods.size() != rems.size()){ 
            std::cout << "Moduli and remainders do not match"; 
            return -1;
        }
        int s = mods.size();
        int64_t N = 1, Ni, inv;

        for(int i = 0; i < s; i++){
            
            for(int j = i + 1; j < s; j++){

                // Ensuring all moduli are pairwise coprime
                if(gcd(mods[i], mods[j]) != 1){ 
                    std::cout << "Moduli are not coprime";
                    return -1;
                }
            }
            N *= mods[i];
        }
        for(int i = 0; i < s; i++){
            Ni = N / mods[i];
            inv = mod_inv(Ni, mods[i]);
            res += inv * Ni * rems[i];
        }
        // To normalize the result
        res %= N;
        if(res < 0) res += N;
        
        return res;
    }
    
}