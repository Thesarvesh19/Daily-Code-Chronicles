#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = min(k, m + n);

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        vector<vector<int>> next_dp(n, vector<int>(k + 1, -1));

        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fill(next_dp[j].begin(), next_dp[j].end(), -1);

                if (i == 0 && j == 0) {
                    next_dp[0][0] = 0;
                    continue;
                }

                int val = grid[i][j];
                int cost = val > 0 ? 1 : 0;

                for (int c = cost; c <= k; c++) {
                    int prev_c = c - cost;
                    int mx = -1;

                    if (i > 0 && dp[j][prev_c] != -1) {
                        mx = dp[j][prev_c];
                    }
                    if (j > 0 && next_dp[j - 1][prev_c] != -1) {
                        mx = max(mx, next_dp[j - 1][prev_c]);
                    }

                    if (mx != -1) {
                        next_dp[j][c] = mx + val;
                    }
                }
            }
            swap(dp, next_dp);
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][c]);
        }
        return ans;
    }
};
