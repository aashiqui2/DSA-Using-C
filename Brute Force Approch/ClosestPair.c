#include <stdio.h>
#include <float.h>
#include <math.h>

float distance(int p1[], int p2[])
{
    return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
}

float bruteForceClosestPair(int points[][2], int n, int p1[], int p2[])
{
    float minDist = FLT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float dist = distance(points[i], points[j]);
            if (dist < minDist)
            {
                minDist = dist;
                p1[0] = points[i][0];
                p1[1] = points[i][1];
                p2[0] = points[j][0];
                p2[1] = points[j][1];
            }
        }
    }
    return minDist;
}

int main()
{

    int points[][2] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);

    int p1[2], p2[2];

    float minDist = bruteForceClosestPair(points, n, p1, p2);

    printf("The smallest distance is %.2f between points (%d, %d) and (%d, %d)\n",
           minDist, p1[0], p1[1], p2[0], p2[1]);

    return 0;
}

/* #include <stdio.h>
#include <float.h>
#include <math.h>

struct Point {
    int x, y;
};

// Function to calculate the Euclidean distance between two points
float distance(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


float bruteForceClosestPair(struct Point points[], int n, struct Point *p1, struct Point *p2) {
    float minDist = FLT_MAX;


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                // Store the points with the minimum distance
                *p1 = points[i];
                *p2 = points[j];
            }
        }
    }
    return minDist;
}

int main() {
    struct Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);

    struct Point p1, p2;

    float minDist = bruteForceClosestPair(points, n, &p1, &p2);

    printf("The smallest distance is %.2f between points (%d, %d) and (%d, %d)\n",
           minDist, p1.x, p1.y, p2.x, p2.y);

    return 0;
}
// time complexity O(n^2)
 */