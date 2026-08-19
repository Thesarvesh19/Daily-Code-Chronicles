using System;
using System.Collections.Generic;

public class Solution
{
    public int MaxNumberOfFamilies(int n, int[][] reservedSeats)
    {
        Dictionary<int, HashSet<int>> reserved = new();

        foreach (int[] seat in reservedSeats)
        {
            if (!reserved.ContainsKey(seat[0]))
                reserved[seat[0]] = new HashSet<int>();

            reserved[seat[0]].Add(seat[1]);
        }

        int ans = (n - reserved.Count) * 2;

        foreach (HashSet<int> seats in reserved.Values)
        {
            bool left = !seats.Contains(2)
                     && !seats.Contains(3)
                     && !seats.Contains(4)
                     && !seats.Contains(5);

            bool middle = !seats.Contains(4)
                       && !seats.Contains(5)
                       && !seats.Contains(6)
                       && !seats.Contains(7);

            bool right = !seats.Contains(6)
                      && !seats.Contains(7)
                      && !seats.Contains(8)
                      && !seats.Contains(9);

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
}
