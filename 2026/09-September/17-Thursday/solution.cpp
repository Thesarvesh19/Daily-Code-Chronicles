class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // prefixSum -> latest index
        unordered_map<int, int> mp;
        mp[0] = 0;

        // best[i] = minimum length of a valid subarray
        // completely inside the first i elements
        vector<int> best(n + 1, INF);

        int sum = 0;
        int ans = INF;

        for (int i = 1; i <= n; i++) {
            sum += arr[i - 1];

            // We can always carry forward the previous best.
            best[i] = best[i - 1];

            // Need previous prefix sum = sum - target
            if (mp.count(sum - target)) {
                int j = mp[sum - target];

                // Subarray [j, i-1] has sum = target
                int len = i - j;

                // best[j] lies completely before this subarray,
                // so the two subarrays cannot overlap.
                if (best[j] != INF) {
                    ans = min(ans, best[j] + len);
                }

                // Update best for the current prefix.
                best[i] = min(best[i], len);
            }

            // Store the latest position of this prefix sum.
            mp[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};
