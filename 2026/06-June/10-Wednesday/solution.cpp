#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

class Solution {
public:
    long long maxTotalValue(std::vector<int>& nums, int k) {
        int n = nums.size();
        int maxLog = std::log2(n) + 1;
        
        std::vector<std::vector<int>> maxST(n, std::vector<int>(maxLog));
        std::vector<std::vector<int>> minST(n, std::vector<int>(maxLog));
        std::vector<int> logTable(n + 1);

        for (int i = 2; i <= n; i++)
            logTable[i] = logTable[i / 2] + 1;

        for (int i = 0; i < n; i++) {
            maxST[i][0] = nums[i];
            minST[i][0] = nums[i];
        }

        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                maxST[i][j] = std::max(maxST[i][j - 1], maxST[i + (1 << (j - 1))][j - 1]);
                minST[i][j] = std::min(minST[i][j - 1], minST[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto getRangeValue = [&](int l, int r) {
            int len = r - l + 1;
            int j = logTable[len];
            int mx = std::max(maxST[l][j], maxST[r - (1 << j) + 1][j]);
            int mn = std::min(minST[l][j], minST[r - (1 << j) + 1][j]);
            return (long long)mx - mn;
        };

        // Stores {value, left_index, right_index}
        std::priority_queue<std::tuple<long long, int, int>> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getRangeValue(l, n - 1), l, n - 1});
        }

        long long totalSum = 0;
        for (int i = 0; i < k; i++) {
            auto [val, l, r] = pq.top();
            pq.pop();
            totalSum += val;

            if (r > l) {
                int nextR = r - 1;
                pq.push({getRangeValue(l, nextR), l, nextR});
            }
        }

        return totalSum;
    }
};
