#include<stdio.h>
int main(){
    int a[9]={-15, -6, 0, 7, 9, 23, 54, 82, 101};
    int len=sizeof(a)/sizeof(a[0]);
    int k=82;
    int flag=0;
    for(int i=0;i<len;i++)
    {
        if(k==a[i]){
            flag=1;
            break;
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