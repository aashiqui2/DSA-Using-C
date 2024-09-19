#include <stdio.h>
int setIthBit(int n, int pos)
{
    int mask = (1 << pos);
    n = n | mask;
    return n;
}
int getIthBit(int n, int pos)
{
    int mask = (1 << pos);
    int bitval = n & mask;
    if (bitval)
    {
        return 1;
    }

    return 0;
}
int clearIthBit(int n, int pos)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return n;
}
int clearLastIBits(int n, int pos)
{
    int mask = (-1 << pos);
    n = n & mask;
    return n;
}
int updateIthBit(int n, int pos, int val)
{
    // val represent bit (0 or 1)
    n = clearIthBit(n, pos);
    int mask = (val << pos);
    n = n | mask;
    return n;
}
int clearBItInRange(int n, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
    return n;
}
// O(K)
int count_one(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int convertToBinary(int n)
{
    int ans = 0;
    int temp = 1;
    while (n > 0)
    {
        int last = n & 1;
        ans = ans + (temp * last);
        temp = temp * 10;
        n = n >> 1;
    }
    return ans;
}
// O(n)
int Power(int base, int power)
{
    int box = 1;
    while (power > 0)
    {
        box = base * box;
        power--;
    }
    return box;
}
int fastExpo(int base, int power)
{
    int ans = 1;
    while (power > 0)
    {
        int lastbit = power & 1;
        if (lastbit == 1)
        {
            ans = ans * base;
        }
        base = base * base;
        power = power >> 1;
    }
    return ans;
}
void Findeveodd(int n)
{
    if (n % 2 == 0)
    {
        printf("The number is odd");
    }
    else
    {
        printf("The number is even");
    }
}
void FindOddEven(int n)
{
    if (n & 1 == 1)
    {
        printf("The number is odd");
    }
    else
    {
        printf("The number is even");
    }
}
// Time complexity of the above code is O(logN).
int ispowerOfTwo(int x)
{
    if (x == 0)
        return 0;
    else
    {
        while (x % 2 == 0)
            x /= 2;
        return (x == 1);
    }
}
int isPowerOfTwo(int x)
{
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}

int main()
{
    int n = 13;
    // int n = 31;

    // printf("%d",setIthBit(n, 2));
    // printf("%d", getIthBit(n,1));
    // printf("%d", clearIthBit(n,0));
    // printf("%d",clearLastIBits(n,3));
    // printf("%d", updateIthBit(n, 2, 2));
    // printf("%d",clearBItInRange(n,1,3));
    // printf("%d",count_one(n));
    // printf("%d",convertToBinary(5));
    //! brute force approach
    // printf("%d", Power(2, 5));
    // printf("%d",fastExpo(2,5));
    // !naive approach
    // Findeveodd(4);
    // ! for all the odd number the right most bit is one
    // FindOddEven(3);

    //! naive approach
    // if (ispowerOfTwo(4))
    // {
    //     printf("It is a power of Two");
    // }
    // else
    // {
    //     printf("It is not a power of Two");
    // }

    if (isPowerOfTwo(4))
    {
        printf("It is a power of Two");
    }
    else
    {
        printf("It is not a power of Two");
    }

    return 0;
}
