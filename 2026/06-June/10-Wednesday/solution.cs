using System;
using System.Collections.Generic;

public class Solution
{
    public long MaxTotalValue(int[] nums, int k)
    {
        int n = nums.Length;
        int maxLog = (int)Math.Log(n, 2) + 1;
        int[,] maxSt = new int[n, maxLog];
        int[,] minSt = new int[n, maxLog];
        int[] logTable = new int[n + 1];

        for (int i = 2; i <= n; i++)
            logTable[i] = logTable[i / 2] + 1;

        for (int i = 0; i < n; i++)
        {
            maxSt[i, 0] = nums[i];
            minSt[i, 0] = nums[i];
        }

        for (int j = 1; j < maxLog; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                maxSt[i, j] = Math.Max(maxSt[i, j - 1], maxSt[i + (1 << (j - 1)), j - 1]);
                minSt[i, j] = Math.Min(minSt[i, j - 1], minSt[i + (1 << (j - 1)), j - 1]);
            }
        }

        long GetRangeValue(int l, int r)
        {
            int len = r - l + 1;
            int j = logTable[len];
            int mx = Math.Max(maxSt[l, j], maxSt[r - (1 << j) + 1, j]);
            int mn = Math.Min(minSt[l, j], minSt[r - (1 << j) + 1, j]);
            return (long)mx - mn;
        }

        // PriorityQueue stores (left_index, right_index) with priority based on value
        var pq = new PriorityQueue<(int l, int r), long>(Comparer<long>.Create((a, b) => b.CompareTo(a)));

        for (int l = 0; l < n; l++)
        {
            pq.Enqueue((l, n - 1), GetRangeValue(l, n - 1));
        }

        long totalSum = 0;
        for (int i = 0; i < k; i++)
        {
            pq.TryDequeue(out var range, out long val);
            totalSum += val;

            if (range.r > range.l)
            {
                int nextR = range.r - 1;
                pq.Enqueue((range.l, nextR), GetRangeValue(range.l, nextR));
            }
        }

        return totalSum;
    }
}
