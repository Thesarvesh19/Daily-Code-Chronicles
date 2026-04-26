// 🔷 Problem: Detect Cycles in a 2D Grid (Recursive DFS - C)

#include <stdbool.h>

int m, n;
bool visited[501][501];

bool dfs(char** grid, int x, int y, int px, int py) {
    if (visited[x][y]) return true;

    visited[x][y] = true;

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];

        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == grid[x][y]) {
            if (nx == px && ny == py) continue;
            if (dfs(grid, nx, ny, x, y)) return true;
        }
    }
    return false;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
    m = gridSize;
    n = gridColSize[0];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (dfs(grid, i, j, -1, -1))
                    return true;
            }
        }
    }
    return false;
}
