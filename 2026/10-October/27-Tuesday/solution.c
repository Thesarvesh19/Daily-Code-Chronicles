#include <stdlib.h>
#include <string.h>

char** createGrid(int m, int n, int* returnSize) {
    char** grid = (char**)malloc(m * sizeof(char*));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        grid[i] = (char*)malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++) {
            grid[i][j] = '#';
        }

        grid[i][n] = '\0';
    }

    for (int j = 0; j < n; j++) {
        grid[0][j] = '.';
    }

    for (int i = 0; i < m; i++) {
        grid[i][n - 1] = '.';
    }

    return grid;
}
