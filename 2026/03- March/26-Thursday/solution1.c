#include <stdbool.h>
#include <stdlib.h>

// simple hashmap using array (constraint-safe assumption)
#define MAXV 1000001

bool check(int** g, int m, int n) {
    long s1 = 0, s2 = 0;

    int* cnt1 = (int*)calloc(MAXV, sizeof(int));
    int* cnt2 = (int*)calloc(MAXV, sizeof(int));

    // total sum and count
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = g[i][j];
            s2 += x;
            cnt2[x]++;
        }
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            int x = g[i][j];
            s1 += x;
            s2 -= x;

            cnt1[x]++;
            cnt2[x]--;
        }

        if (s1 == s2) {
            free(cnt1); free(cnt2);
            return true;
        }

        if (s1 < s2) {
            long diff = s2 - s1;
            if (diff < MAXV && cnt2[diff] > 0) {
                if (
                    (m - i - 1 > 1 && n > 1) ||
                    (i == m - 2 && (g[i + 1][0] == diff || g[i + 1][n - 1] == diff)) ||
                    (n == 1 && (g[i + 1][0] == diff || g[m - 1][0] == diff))
                ) {
                    free(cnt1); free(cnt2);
                    return true;
                }
            }
        } else {
            long diff = s1 - s2;
            if (diff < MAXV && cnt1[diff] > 0) {
                if (
                    (i + 1 > 1 && n > 1) ||
                    (i == 0 && (g[0][0] == diff || g[0][n - 1] == diff)) ||
                    (n == 1 && (g[0][0] == diff || g[i][0] == diff))
                ) {
                    free(cnt1); free(cnt2);
                    return true;
                }
            }
        }
    }

    free(cnt1);
    free(cnt2);
    return false;
}

int** transpose(int** grid, int m, int n) {
    int** t = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        t[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            t[j][i] = grid[i][j];
        }
    }

    return t;
}

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    if (check(grid, m, n)) return true;

    int** t = transpose(grid, m, n);
    bool res = check(t, n, m);

    for (int i = 0; i < n; i++) free(t[i]);
    free(t);

    return res;
}
