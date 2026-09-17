using System;
using System.Collections.Generic;

public class Solution
{
    public int MinSumOfLengths(int[] arr, int target)
    {
        int n = arr.Length;
        int INF = 1_000_000_000;

        // prefix sum -> latest index
        Dictionary<int, int> prefix = new Dictionary<int, int>();
        prefix[0] = 0;

        // best[i] = minimum length of a valid subarray
        // completely inside the first i elements
        int[] best = new int[n + 1];

        for (int i = 0; i <= n; i++)
            best[i] = INF;

        int sum = 0;
        int ans = INF;

        for (int i = 1; i <= n; i++)
        {
            sum += arr[i - 1];

            // Carry forward the previous best
            best[i] = best[i - 1];

            // Look for a previous prefix sum
            if (prefix.ContainsKey(sum - target))
            {
                int j = prefix[sum - target];

                // Subarray [j, i - 1]
                int length = i - j;

                // best[j] is completely before this subarray
                if (best[j] != INF)
                {
                    ans = Math.Min(ans, best[j] + length);
                }

                best[i] = Math.Min(best[i], length);
            }

            // Store latest occurrence
            prefix[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
}
