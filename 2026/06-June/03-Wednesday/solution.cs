using System;

public class Solution
{
    private long Solve(int[] s1, int[] d1,
                       int[] s2, int[] d2)
    {
        int m = s2.Length;

        long[][] rides = new long[m][];

        for (int i = 0; i < m; i++)
        {
            rides[i] = new long[]
            {
                s2[i],
                d2[i]
            };
        }

        Array.Sort(rides,
            (a, b) => a[0].CompareTo(b[0]));

        long[] start = new long[m];
        long[] prefDur = new long[m];
        long[] sufFinish = new long[m];

        for (int i = 0; i < m; i++)
            start[i] = rides[i][0];

        prefDur[0] = rides[0][1];

        for (int i = 1; i < m; i++)
        {
            prefDur[i] =
                Math.Min(prefDur[i - 1],
                         rides[i][1]);
        }

        sufFinish[m - 1] =
            rides[m - 1][0] + rides[m - 1][1];

        for (int i = m - 2; i >= 0; i--)
        {
            sufFinish[i] = Math.Min(
                sufFinish[i + 1],
                rides[i][0] + rides[i][1]
            );
        }

        long ans = long.MaxValue;

        for (int i = 0; i < s1.Length; i++)
        {
            long finish1 =
                (long)s1[i] + d1[i];

            int pos = LowerBound(start, finish1);

            if (pos > 0)
            {
                ans = Math.Min(
                    ans,
                    finish1 + prefDur[pos - 1]
                );
            }

            if (pos < m)
            {
                ans = Math.Min(
                    ans,
                    sufFinish[pos]
                );
            }
        }

        return ans;
    }

    private int LowerBound(long[] arr, long target)
    {
        int l = 0;
        int r = arr.Length;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    public long EarliestFinishTime(
        int[] landStartTime,
        int[] landDuration,
        int[] waterStartTime,
        int[] waterDuration)
    {
        return Math.Min(
            Solve(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            ),
            Solve(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration
            )
        );
    }
}
