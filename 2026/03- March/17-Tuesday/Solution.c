#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    // Build heights
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
    }

    int maxArea = 0;

    for (int i = 0; i < m; i++) {
        qsort(matrix[i], n, sizeof(int), compare);

        for (int j = n - 1; j >= 0; j--) {
            int height = matrix[i][j];
            int width = n - j;
            int area = height * width;

            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    return maxArea;
}
