#include <stdio.h>
#include <stdlib.h>

int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    
    int* colSum = (int*)calloc(n, sizeof(int));
    int count = 0; 
 
    for (int i = 0; i < m; i++) { 
        int rowPrefix = 0; 

        for (int j = 0; j < n; j++) {
            // Update column sum
            colSum[j] += grid[i][j];

            // Build prefix sum for (0,0) → (i,j)
            rowPrefix += colSum[j];

            if (rowPrefix <= k) {
                count++;
            }
        }
    }

    free(colSum);
    return count;
}
