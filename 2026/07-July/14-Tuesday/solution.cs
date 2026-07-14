using System;

public class Solution
{
    private const int MOD = 1000000007;

    private int[] nums;
    private int n;
    private int[,,] memo;

    public int SubsequencePairCount(int[] nums)
    {
        this.nums = nums;
        n = nums.Length;

        memo = new int[n + 1, 201, 201];

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= 200; j++)
                for (int k = 0; k <= 200; k++)
                    memo[i, j, k] = -1;

        return DFS(0, 0, 0);
    }

    private int DFS(int index, int gcd1, int gcd2)
    {
        if (index == n)
            return (gcd1 != 0 && gcd1 == gcd2) ? 1 : 0;

        if (memo[index, gcd1, gcd2] != -1)
            return memo[index, gcd1, gcd2];

        long ans = 0;

        // Skip current number
        ans += DFS(index + 1, gcd1, gcd2);

        // Add to first subsequence
        int nextGcd1 = gcd1 == 0 ? nums[index] : GCD(gcd1, nums[index]);
        ans += DFS(index + 1, nextGcd1, gcd2);

        // Add to second subsequence
        int nextGcd2 = gcd2 == 0 ? nums[index] : GCD(gcd2, nums[index]);
        ans += DFS(index + 1, gcd1, nextGcd2);

        memo[index, gcd1, gcd2] = (int)(ans % MOD);
        return memo[index, gcd1, gcd2];
    }

    private int GCD(int a, int b)
    {
        while (b != 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}
