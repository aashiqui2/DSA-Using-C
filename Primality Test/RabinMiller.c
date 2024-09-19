#include <stdio.h>
#include <stdlib.h>

// It returns (a^d) % mod n
long long power_mod(long long base, long long power, long long n)
{
    long long result = 1;
    base = base % n; // Reduce base modulo n

    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = (result * base) % n; // Multiply if power is odd
        }
        power = power / 2;
        base = (base * base) % n; // Square the base
    }

    return result;
}

long long random_range(long long low, long long high)
{
    return low + rand() % (high - low + 1);
}

int miller_rabin_test(long long n, int k)
{
    if (n <= 1 || n == 4)
        return 0; // Handle trivial cases
    if (n <= 3)
        return 1; // n is prime if n <= 3

    // Find d such that n-1 = 2^s * d with d odd
    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    // Perform k iterations of the test
    for (int i = 0; i < k; i++)
    {
        long long a = random_range(2, n - 2); // Step 1: Choose random a
        long long x = power_mod(a, d, n);     // Step 2: Compute X = a^d (mod n)

        if (x == 1 || x == n - 1)
        {
            continue; // Step 2: If X ≡ ±1 (mod n), continue
        }

        // Otherwise, repeat r times
        int composite = 1; // Assume n is composite
        for (int r = 1; r <= s - 1; r++)
        {
            x = power_mod(x, 2, n); // Compute X = a^(2^r * d) % n
            if (x == 1)
            {
                return 0; // n is composite (definitely not prime) based on the image
            }
            else if (x == n - 1)
            {
                composite = 0; // n is probably prime (X ≡ -1 mod n)
                break;
            }
        }
        if (composite)
        {
            return 0; // If no -1 was found, n is composite
        }
        return 1; // n is probably prime
    }
}

int main()
{
    long long n;
    int k = 5; // Number of iterations (higher k increases accuracy)

    printf("Enter number to test for primality: ");
    scanf("%lld", &n);

    if (miller_rabin_test(n, k))
    {
        printf("%lld is probably prime.\n", n);
    }
    else
    {
        printf("%lld is composite.\n", n);
    }

    return 0;
}
