#include<stdio.h>
#include<string.h>
#define MAX_NAME 256
#define TABLE_SIZE 10
typedef struct {
    char name[MAX_NAME];
    int age;
}person;
unsigned int hash(char *name)
{
    int length=strnlen(name,MAX_NAME);
    unsigned int hash_value=0;
    for(int i=0;i<length;i++)
    {
        hash_value+=name[i];
        hash_value=(hash_value *name[i]) % TABLE_SIZE; //(0 - table size -1)
    }
    return hash_value;
    // return 5;
}
int main(){
    printf("Jacob => %u\n",hash("Jacob"));
    printf("Natalie => %u\n",hash("Natalie"));
    printf("Sara => %u\n",hash("Sara"));
    printf("Mpho => %u\n",hash("Mpho"));
    printf("Tebogo => %u\n",hash("Tebogo"));
    printf("Ron => %u\n",hash("Ron"));
    printf("Jane => %u\n",hash("Jane"));
    printf("Maren => %u\n",hash("Maren"));
    printf("Bill => %u\n",hash("Bill"));
    
return 0;
}

//! Not Completed (reference->jacob sorber)