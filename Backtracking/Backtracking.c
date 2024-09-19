#include <stdio.h>
#include <string.h>

void printPermutation(char *str, char *perm, int index) {
    int len = strlen(str);
    
    if (len == 0) {
        printf("%s\n", perm);
        return;
    }

    for (int i = 0; i < len; i++) {
        char currChar = str[i];
        char newStr[100]; 
        strncpy(newStr, str, i); 
        newStr[i] = '\0';
        strcat(newStr, str + i + 1); 
        
        char newPerm[100]; 
        strcpy(newPerm, perm);
        int permLen = strlen(newPerm);
        newPerm[permLen] = currChar; 
        newPerm[permLen + 1] = '\0';
        
        printPermutation(newStr, newPerm, index + 1);
    }
}

int main() {
    char str[] = "ABC";
    char perm[100] = ""; 
    
    printPermutation(str, perm, 0);
    return 0;
}
