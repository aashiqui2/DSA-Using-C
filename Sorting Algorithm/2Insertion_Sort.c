#include <stdio.h>
int main()
{
    int a[] = {5, 4, 10, 1, 6, 2};
    int n = 6;
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
// Time Complexity is O(n^2)