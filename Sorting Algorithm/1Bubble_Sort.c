#include <stdio.h>
int main()
{
    int a[] = {15, 16, 6, 8, 5};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
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
    //     printf("%d ",a[i]);
    // }

    return 0;
}

// Time Complexity is O(n^2)

// 15 16 6 8 5 15>16
// 15 16 6 8 5 16>6
// 15 6 16 8 5 16>8
// 15 6 8 16 5 16>5
// 15 6 8 5 16