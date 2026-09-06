using System;

public class Solution
{
    public int NumDistinct(string s, string t)
    {
        int n = t.Length;
        ulong[] dp = new ulong[n + 1];
        dp[0] = 1;

        foreach (char ch in s)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (ch == t[j])
                {
                    dp[j + 1] += dp[j];
                }
            }
        }

        return (int)dp[n];
    }
}
