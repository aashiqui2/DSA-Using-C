#include <stdio.h>
#include <limits.h>
int main()
{
    int a[9] = {-15, -6, 0, 7, 9, 23, 54, 82, 101};
    int len = sizeof(a) / sizeof(a[0]);
    int k = 82;
    int flag=0;
    //? potentisla issue if the value is large
    // int left = INT_MAX - 1;
    // int right = INT_MAX;
    // printf("%d %d\n", left, right);
    // int mid=(left+right)/2;
    // int mid=left+(right-left)/2;
    // printf("%d", mid);

    int left=0,right=len-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(a[mid]==k){
            flag=1;
            break;
        }
        else if(a[mid]<k){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    if(flag)
    {
        printf("SUCCESS");
    }
    else{
        printf("FAILURE");
    }
    return 0;
}