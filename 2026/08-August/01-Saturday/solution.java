class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        Integer[][] memo = new Integer[n][n];
        return dfs(nums, 0, n - 1, memo) >= 0;
    }

    private int dfs(int[] nums, int left, int right, Integer[][] memo) {
        if (left == right) {
            return nums[left];
        }

        if (memo[left][right] != null) {
            return memo[left][right];
        }

        int takeLeft = nums[left] - dfs(nums, left + 1, right, memo);
        int takeRight = nums[right] - dfs(nums, left, right - 1, memo);

        return memo[left][right] = Math.max(takeLeft, takeRight);
    }
}
