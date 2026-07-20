/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and *columnSizes array must be malloced.
 */

int** shiftGrid(int** grid, int gridSize, int* gridColSize,
                int k, int* returnSize, int** returnColumnSizes) {

    int rows = gridSize;
    int cols = gridColSize[0];
    int total = rows * cols;

    k %= total;

    int **result = (int **)malloc(rows * sizeof(int *));
    *returnColumnSizes = (int *)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            int current = r * cols + c;
            int target = (current + k) % total;

            int nr = target / cols;
            int nc = target % cols;

            result[nr][nc] = grid[r][c];
        }
    }

    *returnSize = rows;
    return result;
}
