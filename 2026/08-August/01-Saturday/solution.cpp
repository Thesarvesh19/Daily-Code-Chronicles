class Solution {
public:
    vector<vector<int>> memo;

    int dfs(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];

        if (memo[left][right] != INT_MIN)
            return memo[left][right];

        int takeLeft = nums[left] - dfs(nums, left + 1, right);
        int takeRight = nums[right] - dfs(nums, left, right - 1);

        return memo[left][right] = max(takeLeft, takeRight);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, vector<int>(n, INT_MIN));
        return dfs(nums, 0, n - 1) >= 0;
    }
};
