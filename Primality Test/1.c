#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform modular exponentiation (x^d) % t
int pow_mod(int x, int d, int t) {
    int res = 1;  // Initialize result
    x = x % t;    // Update x if it is more than t

    while (d > 0) {
        // If d is odd, multiply x with result
        if (d & 1) {
            res = (res * x) % t;
        }
        // d must be even now
        d = d >> 1;  // Divide d by 2
        x = (x * x) % t;  // Change x to x^2
    }

    return res;
}

// Miller-Rabin primality test for a single iteration
int miller_rabin(int d, int n) {
    // Pick a random number in [2, n-2]
    int a = 2 + rand() % (n - 4);

    // Compute a^d % n
    int x = pow_mod(a, d, n);

    if (x == 1 || x == n - 1) {
        return 1;  // Probably prime
    }

    // Continue squaring x while one of the conditions is met
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == n - 1) {
            return 1;  // Probably prime
        }
        if (x == 1) {
            return 0;  // Definitely composite
        }
    }

    return 0;  // Composite
}

// Function to check if n is prime with k iterations
int is_prime(int n, int k) {
    // Handle corner cases
    if (n <= 3) {
        return 1;  // 2 and 3 are prime
    }
    if (n <= 1 || n == 4) {
        return 0;  // 1 and 4 are not prime
    }

    // Find d such that n-1 = 2^s * d (d odd)
    int d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    // Perform the Miller-Rabin test k times
    for (int i = 0; i < k; i++) {
        if (!miller_rabin(d, n)) {
            return 0;  // Composite
        }
    }

    return 1;  // Probably prime
}


int main() {
    int k = 4;  
    srand(time(NULL)); 

    printf("Prime numbers less than 70: \n");

    for (int n = 1; n < 70; n++) {
        if (is_prime(n, k)) {
            printf("%d ", n);
        }
    }
    printf("\n");

    return 0;
}
