#include <stdio.h>
#include <string.h>

void bruteForceStringMatch(char text[], char pattern[]) {
    int n = strlen(text);     // Length of the text
    int m = strlen(pattern);  // Length of the pattern

    // Slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check the pattern at the current position
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;  // Mismatch found, break out of the loop
            }
        }

        // If the pattern is found
        if (j == m) {
            printf("Pattern found at index %d \n", i);
        }
    }
}

int main() {
    char text[] = "AABAACAADAABAABA";    
    char pattern[] = "AABA";             

    bruteForceStringMatch(text, pattern);

    return 0;
}

// time complexity  O(nm)
// comparision m(n-m+1)
