#include <stdio.h>
int main()
{
    int a[] = {7, 4, 10, 8, 3, 1};
    int n = 6;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        break;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    return 0;
}

// Time Complexity is O(n^2)
// 7 4 10 8 3 1  7>4
// 4 7 10 8 3 1  4>10
// 4 7 10 8 3 1  4>8
// 4 7 10 8 3 1  4>3
// 3 7 10 8 4 1  3>1
// 1 7 10 8 4 3