using System;

public class Solution
{
    public int RemoveCoveredIntervals(int[][] intervals)
    {
        Array.Sort(intervals, (a, b) =>
        {
            if (a[0] == b[0])
                return b[1].CompareTo(a[1]);

            return a[0].CompareTo(b[0]);
        });

        int answer = 0;
        int farthestEnd = -1;

        foreach (var interval in intervals)
        {
            if (interval[1] > farthestEnd)
            {
                answer++;
                farthestEnd = interval[1];
            }
        }

        return answer;
    }
}
