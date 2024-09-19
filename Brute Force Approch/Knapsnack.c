#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

int getMaxVal(int n, int w[], int v[], int c, int i) {
    if (i == n || c <= 0) {
        return 0;
    }
    int vin, vex;
    if (w[i] <= c) { // Check if item can be included
        vin = getMaxVal(n, w, v, c - w[i], i + 1) + v[i];
        vex = getMaxVal(n, w, v, c, i + 1);
        return max(vin, vex);
    } else {
        vex = getMaxVal(n, w, v, c, i + 1);
        return vex;
    }
}

int main() {
    int item = 4;
    int w[100] = {7, 3, 4, 5};
    int v[100] = {42, 12, 40, 25};
    int c = 10;
    int result = getMaxVal(item, w, v, c, 0);
    printf("%d\n", result);
    return 0;
}
