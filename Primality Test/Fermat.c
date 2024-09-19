#include <stdio.h>


// It returns (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        // Now exp is even, so divide it by 2
        exp = exp >> 1;
        base = (base * base) % mod; // Square the base
    }
    return result;
}

// Fermat's Little Theorem to check if a^(n-1) ≡ 1 (mod n) for prime n
int fermatTest(long long a, long long n) {
    // If n is prime, Fermat's theorem says a^(n-1) ≡ 1 mod n
    if (modExp(a, n-1, n) == 1) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    long long a, n;
    
    printf("Enter a (base): ");
    scanf("%lld", &a);
    
    printf("Enter n (modulus, should be a prime): ");
    scanf("%lld", &n);
    
    
    if (fermatTest(a, n)) {
        printf("Fermat's theorem holds: %lld^(%lld-1) ≡ 1 mod %lld\n", a, n, n);
    } else {
        printf("Fermat's theorem does not hold.\n");
    }
    
    return 0;
}
