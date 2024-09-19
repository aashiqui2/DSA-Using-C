### Closest Pair Problem

The **Closest Pair Problem** is a classic computational geometry problem. The goal is to find the **two closest points** in a set of points in a 2D plane, based on the Euclidean distance between them.

---

### **Problem Statement**:
Given a set of `n` points in a 2D plane, find the pair of points that are the closest to each other.

---

### **Brute Force Approach**:
In the brute force approach, you simply compute the distance between every possible pair of points and return the pair with the smallest distance.

#### **Time Complexity**:
- **O(n²)**: This is because you need to calculate the distance for every possible pair of points, which results in n(n-1)/2 comparisons (approximately n²/2).

---

### **Algorithm Steps for Brute Force**:
1. For each point, compute the distance to every other point.
2. Keep track of the minimum distance found so far.
3. Return the pair of points that has the smallest distance.

### **C Code for Brute Force Closest Pair**:

```c
#include <stdio.h>
#include <float.h>
#include <math.h>

// Structure to represent a point in 2D plane
struct Point {
    int x, y;
};

// Function to calculate the Euclidean distance between two points
float distance(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the closest pair of points using brute force
float bruteForceClosestPair(struct Point points[], int n) {
    float minDist = FLT_MAX; // Set initial distance to a large value

    // Compare every pair of points
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

int main() {
    struct Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);

    printf("The smallest distance is %.2f\n", bruteForceClosestPair(points, n));

    return 0;
}
```

---

### **Explanation**:

1. **Distance Calculation**:  
   - We calculate the **Euclidean distance** between two points `(x1, y1)` and `(x2, y2)` using the formula:
   \[
   d = \sqrt{(x1 - x2)^2 + (y1 - y2)^2}
   \]
   
2. **Nested Loops**:
   - The algorithm loops over each point and calculates its distance to every other point, keeping track of the minimum distance found.

3. **Minimum Distance**:  
   - The minimum distance between any two points is returned.

---

### **Example**:

For the input points:
```
{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}
```

The output will be:
```
The smallest distance is 1.41
```

This corresponds to the points `(2, 3)` and `(3, 4)` which are closest.

---

### **Time Complexity**:

- **O(n²)**: Since the brute force algorithm compares every pair of points, its time complexity is quadratic.
  
---

### **Optimized Approach**: **Divide and Conquer**

For larger datasets, the brute force approach becomes inefficient. A more optimized approach using **Divide and Conquer** can reduce the time complexity to **O(n log n)**.

#### Steps:
1. **Sort** the points based on their x-coordinates.
2. **Divide** the set of points into two halves.
3. Recursively find the closest pair of points in each half.
4. **Merge**: Compare the points across the divide (within a certain distance threshold) to find the closest pair overall.

---

### Summary:
- The brute force approach for finding the closest pair has a time complexity of **O(n²)**.
- For large sets of points, **Divide and Conquer** reduces the complexity to **O(n log n)**, making it more efficient.
