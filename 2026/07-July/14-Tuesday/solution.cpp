#include <vector>
#include <numeric>
#include <cstring>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;

    int n;
    vector<int> nums;

    // Maximum value in nums is <= 200
    int dp[201][201][201];

    int solve(int idx, int gcd1, int gcd2) {
        if (idx == n) {
            return (gcd1 != 0 && gcd1 == gcd2) ? 1 : 0;
        }

        int &res = dp[idx][gcd1][gcd2];
        if (res != -1)
            return res;

        long long ans = 0;

        // 1. Skip current element
        ans += solve(idx + 1, gcd1, gcd2);

        // 2. Put current element into first subsequence
        int newGcd1 = (gcd1 == 0) ? nums[idx] : gcd(gcd1, nums[idx]);
        ans += solve(idx + 1, newGcd1, gcd2);

        // 3. Put current element into second subsequence
        int newGcd2 = (gcd2 == 0) ? nums[idx] : gcd(gcd2, nums[idx]);
        ans += solve(idx + 1, gcd1, newGcd2);

        res = ans % MOD;
        return res;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};
