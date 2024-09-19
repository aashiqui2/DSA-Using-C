#include <stdio.h>

int isSubsetSum(int set[], int n, int target_sum) {
    int total_subsets = 1 << n;  // 2^n subsets (using bit manipulation)

    // Loop through all possible subsets
    for (int subset_mask = 0; subset_mask < total_subsets; subset_mask++) {
        int current_sum = 0;

        // Check each bit of the subset mask
        for (int i = 0; i < n; i++) {
            // If the i-th bit is set in subset_mask, include set[i] in the subset
            if (subset_mask & (1 << i)) {
                current_sum += set[i];
            }
        }

        // If the sum of this subset is equal to the target sum, return true
        if (current_sum == target_sum) {
            return 1;
        }
    }

    // If no subset has the sum equal to the target sum, return false
    return 0;
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};  
    int target_sum = 9;                // Target sum
    int n = sizeof(set) / sizeof(set[0]);  

    if (isSubsetSum(set, n, target_sum)) {
        printf("Found a subset with the given sum.\n");
    } else {
        printf("No subset with the given sum.\n");
    }

    return 0;
}
