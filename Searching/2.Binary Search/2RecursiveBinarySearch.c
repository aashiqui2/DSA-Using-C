#include <stdio.h>
void bin_search(int a[], int k, int left, int right)
{
    int mid;
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == k)
        {
            printf("Element found at the index of %d",mid);
            return;
        }
        else if (a[mid] < k)
        {
           bin_search(a,k,mid+1,right);
        }
        else
        {
           bin_search(a,k,mid-1,right);
        }
    }
    else{
         printf("FAILURE");
    }
}
int main()
{
    int a[9] = {-15, -6, 0, 7, 9, 23, 54, 82, 101};
    int len = sizeof(a) / sizeof(a[0]);
    int k = 821;
    int flag = 0;
    bin_search(a, k, 0, len - 1);
    return 0;
}