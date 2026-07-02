#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int m = gridSize;
    int n = gridColSize[0];
    
    int dist[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    
    // Max size of the queue needs to handle elements pushed both ways
    int max_size = m * n * 2;
    int (*deque)[2] = malloc(max_size * sizeof(*deque));
    
    // Start head and tail in the middle of the array
    int head = max_size / 2;
    int tail = max_size / 2;
    
    dist[0][0] = grid[0][0];
    deque[tail][0] = 0;
    deque[tail][1] = 0;
    tail++;
    
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    while (head < tail) {
        int r = deque[head][0];
        int c = deque[head][1];
        head++; 
        
        if (r == m - 1 && c == n - 1) {
            bool res = health - dist[r][c] > 0;
            free(deque);
            return res;
        }
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int w = grid[nr][nc];
                if (dist[r][c] + w < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + w;
                    if (w == 0) {
                        head--;
                        deque[head][0] = nr;
                        deque[head][1] = nc;
                    } else {
                        deque[tail][0] = nr;
                        deque[tail][1] = nc;
                        tail++;
                    }
                }
            }
        }
    }
    
    free(deque);
    return false;
}
