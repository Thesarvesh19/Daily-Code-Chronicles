public class Solution
{
    private int?[,] memo;

    public bool PredictTheWinner(int[] nums)
    {
        int n = nums.Length;
        memo = new int?[n, n];

        return Dfs(nums, 0, n - 1) >= 0;
    }

    private int Dfs(int[] nums, int l, int r)
    {
        if (l == r)
            return nums[l];

        if (memo[l, r].HasValue)
            return memo[l, r].Value;

        int left = nums[l] - Dfs(nums, l + 1, r);
        int right = nums[r] - Dfs(nums, l, r - 1);

        memo[l, r] = Math.Max(left, right);
        return memo[l, r].Value;
    }
}
