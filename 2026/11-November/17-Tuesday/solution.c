
#include <string.h>
#include <limits.h>

int minimumChanges(char* s, int k) {
    int n = strlen(s);
    int cost[200][200] = {0};

    // Precompute substring costs.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int len = j - i + 1;
            int best = n;

            for (int d = 1; d < len; d++) {
                if (len % d != 0) {
                    continue;
                }

                int changes = 0;

                for (int offset = 0; offset < d; offset++) {
                    int left = i + offset;
                    int right = j - d + 1 + offset;

                    while (left < right) {
                        if (s[left] != s[right]) {
                            changes++;
                        }

                        left += d;
                        right -= d;
                    }
                }

                if (changes < best) {
                    best = changes;
                }
            }

            cost[i][j] = best;
        }
    }

    // Dynamic programming.
    const int INF = 1000000;
    int dp[201][101];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INF;
        }
    }

    dp[n][0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int parts = 1; parts <= k; parts++) {
            for (int j = i + 1; j < n; j++) {
                if (dp[j + 1][parts - 1] == INF) {
                    continue;
                }

                int current = cost[i][j] +
                              dp[j + 1][parts - 1];

                if (current < dp[i][parts]) {
                    dp[i][parts] = current;
                }
            }
        }
    }

    return dp[0][k];
}
