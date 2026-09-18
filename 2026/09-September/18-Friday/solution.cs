using System;
using System.Collections.Generic;

public class Solution
{
    public IList<string> MaxNumOfSubstrings(string s)
    {
        int n = s.Length;

        // First and last occurrence of each character
        int[] first = new int[26];
        int[] last = new int[26];

        Array.Fill(first, n);
        Array.Fill(last, -1);

        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            first[c] = Math.Min(first[c], i);
            last[c] = i;
        }

        List<(int l, int r)> intervals = new List<(int l, int r)>();

        // Find all valid intervals
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';

            // Only start from the first occurrence
            if (i != first[c])
                continue;

            int l = i;
            int r = last[c];
            bool valid = true;

            for (int j = l; j <= r; j++)
            {
                int x = s[j] - 'a';

                // Character occurs before l
                if (first[x] < l)
                {
                    valid = false;
                    break;
                }

                // Expand the interval
                r = Math.Max(r, last[x]);
            }

            if (valid)
            {
                intervals.Add((l, r));
            }
        }

        // Sort by ending position
        intervals.Sort((a, b) => a.r.CompareTo(b.r));

        List<string> ans = new List<string>();
        int end = -1;

        // Greedily select non-overlapping intervals
        foreach (var interval in intervals)
        {
            int l = interval.l;
            int r = interval.r;

            if (l > end)
            {
                ans.Add(s.Substring(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
}
