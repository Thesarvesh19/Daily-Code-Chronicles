#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxProductPath(int** grid, int m, int n) {
    long long max_dp[m][n];
    long long min_dp[m][n];

    max_dp[0][0] = min_dp[0][0] = grid[0][0];

    // First column
    for (int i = 1; i < m; i++) {
        max_dp[i][0] = min_dp[i][0] = max_dp[i-1][0] * grid[i][0];
    }

    // First row
    for (int j = 1; j < n; j++) {
        max_dp[0][j] = min_dp[0][j] = max_dp[0][j-1] * grid[0][j];
    }

    // Fill DP
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            long long val = grid[i][j];

            long long a = val * max_dp[i-1][j];
            long long b = val * min_dp[i-1][j];
            long long c = val * max_dp[i][j-1];
            long long d = val * min_dp[i][j-1];

            long long max_val = a;
            long long min_val = a;

            if (b > max_val) max_val = b;
            if (c > max_val) max_val = c;
            if (d > max_val) max_val = d;

            if (b < min_val) min_val = b;
            if (c < min_val) min_val = c;
            if (d < min_val) min_val = d;

            max_dp[i][j] = max_val;
            min_dp[i][j] = min_val;
        }
    }

    long long result = max_dp[m-1][n-1];

    if (result < 0) return -1;

    return result % MOD;
}
