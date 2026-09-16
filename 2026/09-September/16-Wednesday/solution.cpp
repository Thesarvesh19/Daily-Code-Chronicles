class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        // prev[i] = ways to form (j - 1) segments
        // using the first i points
        vector<long long> prev(n + 1, 1);

        for (int j = 1; j <= k; j++) {
            vector<long long> curr(n + 1, 0);

            long long prefix = 0;

            for (int i = 2; i <= n; i++) {
                // Add ways to form j-1 segments
                // before starting the new segment
                prefix = (prefix + prev[i - 1]) % MOD;

                // Either:
                // 1. The last point is not used
                // 2. A segment ends at the last point
                curr[i] = (curr[i - 1] + prefix) % MOD;
            }

            prev = curr;
        }

        return prev[n];
    }
};
