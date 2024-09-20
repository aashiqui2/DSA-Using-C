#include <stdio.h>

void findSubset(int set[], int n, int sum) {
    int totalSubsets = 1 << n; // 2^n subsets

    for (int i = 0; i < totalSubsets; i++) {
        int currentSum = 0;
        printf("Subset: ");
        
        for (int j = 0; j < n; j++) {
            // Check if the j-th element is included in the subset
            if (i & (1 << j)) {
                currentSum += set[j];
                printf("%d ", set[j]); // Print the included element
            }
        }

        // Check if the current subset's sum matches the desired sum
        if (currentSum == sum) {
            printf("=> Found a subset with sum %d\n", sum);
            return; // Exit after finding the first valid subset
        }

        printf("\n"); // Print newline for clarity
    }

    printf("No subset with given sum\n");
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    findSubset(set, n, sum);
    return 0;
}
