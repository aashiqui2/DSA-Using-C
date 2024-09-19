### Quick Sort Algorithm Steps:

**Quick Sort** is a divide-and-conquer algorithm that works by selecting a "pivot" element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

Here are the steps involved in the Quick Sort algorithm:

### 1. **Choose a Pivot Element**
   - **Pivot Selection**: Choose a pivot element from the array. Common strategies include picking the first element, the last element, the middle element, or a random element.

### 2. **Partition the Array**
   - **Partitioning**: Rearrange the array so that:
     - All elements less than the pivot are placed to its left.
     - All elements greater than the pivot are placed to its right.
   - The pivot element is now in its correct position in the sorted array.

### 3. **Recursively Apply Quick Sort**
   - **Sub-array Sorting**: Apply the Quick Sort algorithm recursively to the sub-arrays:
     - One sub-array contains elements less than the pivot.
     - The other sub-array contains elements greater than the pivot.

### 4. **Base Case**
   - **Recursion Termination**: The recursion terminates when the sub-array has one or zero elements since it is already sorted by definition.

### Example Walkthrough:

Consider an array: `[10, 7, 8, 9, 1, 5]`

1. **Choose a Pivot**: Let's choose the last element `5` as the pivot.
2. **Partition the Array**: 
   - Rearrange the array so that elements less than `5` are on the left and elements greater than `5` are on the right.
   - After partitioning, the array becomes: `[1, 5, 8, 9, 10, 7]` (Note that `5` is now in its correct position).
3. **Recursive Quick Sort**: 
   - Apply Quick Sort to the sub-array `[1]` (left side of the pivot). It's already sorted.
   - Apply Quick Sort to the sub-array `[8, 9, 10, 7]` (right side of the pivot).
   - Continue this process recursively.

### Time Complexity:
- **Worst-case**: \(O(n^2)\) - occurs when the pivot is the smallest or largest element, leading to unbalanced partitions.
- **Average-case**: \(O(n \log n)\) - occurs with a good pivot selection strategy leading to balanced partitions.
- **Best-case**: \(O(n \log n)\) - occurs when the pivot consistently divides the array into two equal halves.

### Space Complexity:
- **Space Complexity**: \(O(\log n)\) for the recursive stack space.

### Summary:

- **Quick Sort** is efficient for large datasets, with an average and best-case time complexity of \(O(n \log n)\).
- The key operation is partitioning, which organizes the array around the pivot.
- Careful pivot selection and understanding the partitioning process are essential for effective implementation.