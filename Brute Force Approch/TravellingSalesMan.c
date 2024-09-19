#include <stdio.h>
#include <limits.h>

#define N 4

// Function to calculate the total distance of a given tour
int calculateTourDistance(int dist[N][N], int tour[]) {
    int totalDistance = 0;
    for (int i = 0; i < N - 1; i++) {
        totalDistance += dist[tour[i]][tour[i + 1]];
    }
    totalDistance += dist[tour[N - 1]][tour[0]]; // Return to the start
    return totalDistance;
}

// Function to find the minimum tour distance using brute force
void tspBruteForce(int dist[N][N], int tour[], int visited[], int currPos, int count, int cost, int *minCost, int minTour[]) {
    if (count == N && dist[currPos][0]) { // All cities visited
        int tourCost = cost + dist[currPos][0]; // Return to start
        if (tourCost < *minCost) {
            *minCost = tourCost;
            for (int i = 0; i < N; i++) {
                minTour[i] = tour[i];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[currPos][i]) {
            visited[i] = 1;
            tour[count] = i;
            tspBruteForce(dist, tour, visited, i, count + 1, cost + dist[currPos][i], minCost, minTour);
            visited[i] = 0; // Backtrack
        }
    }
}

int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int tour[N];
    int visited[N] = {0}; // Keeps track of visited cities
    int minCost = INT_MAX;
    int minTour[N];

    visited[0] = 1;
    tour[0] = 0; // Starting city

    tspBruteForce(dist, tour, visited, 0, 1, 0, &minCost, minTour);

    printf("Minimum cost: %d\n", minCost);
    printf("Tour: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", minTour[i]);
    }
    printf("\n");

    return 0;
}
/*
    A   B   C   D
A [ 0, 10, 15, 20 ]
B [10,  0, 35, 25 ]
C [15, 35,  0, 30 ]
D [20, 25, 30,  0 ]


Edges:
A to B: 10
A to C: 15
A to D: 20
B to C: 35
B to D: 25
C to D: 30

     10
  A ------ B
  | \    / |
  |  \  /  |
  |   \/   |
  |   /\   |
  |  /  \  |
  | /    \ |
 15      25
  |        |
  |        |
  |        |
  C ------ D
      30


Path: A → B → D → C → A

A to B: 10
B to D: 25
D to C: 30
C to A: 15
Total Distance Calculation
Total distance = A to B + B to D + D to C + C to A =10+25+30+15=80
*/
