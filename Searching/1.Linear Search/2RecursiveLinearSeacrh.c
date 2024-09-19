#include <stdio.h>
void linear_search(int a[], int len, int idx, int data)
{
    if (idx < len)
    {
        if (a[idx] == data)
        {
            printf("Success");
            return;
        }
        else
        {
            linear_search(a, len, idx + 1, data);
        }
    }
    else{
        printf("FAILURE");
        return;
    }
}
int main()
{
    int a[9] = {-15, -6, 0, 7, 9, 23, 54, 82, 101};
    int len = sizeof(a) / sizeof(a[0]);
    int k = 22;
    linear_search(a, len, 0, k);

    return 0;
}