using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution
{
    private const int MAX = 1000001;

    public string SmallestPalindrome(string s, int k)
    {
        int[] freq = new int[26];

        foreach (char c in s)
            freq[c - 'a']++;

        int[] half = new int[26];
        string mid = "";

        for (int i = 0; i < 26; i++)
        {
            half[i] = freq[i] / 2;
            if ((freq[i] & 1) == 1)
                mid = ((char)('a' + i)).ToString();
        }

        if (CountWays(half) < k)
            return "";

        StringBuilder left = new StringBuilder();
        int halfLen = half.Sum();

        for (int pos = 0; pos < halfLen; pos++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (half[i] == 0)
                    continue;

                half[i]--;
                int ways = CountWays(half);

                if (ways >= k)
                {
                    left.Append((char)('a' + i));
                    break;
                }

                k -= ways;
                half[i]++;
            }
        }

        char[] right = left.ToString().ToCharArray();
        Array.Reverse(right);

        return left.ToString() + mid + new string(right);
    }

    private int CountWays(int[] cnt)
    {
        int total = cnt.Sum();
        long res = 1;

        foreach (int f in cnt)
        {
            res *= NCk(total, f);
            if (res >= MAX)
                return MAX;
            total -= f;
        }

        return (int)res;
    }

    private long NCk(int n, int k)
    {
        k = Math.Min(k, n - k);
        long res = 1;

        for (int i = 1; i <= k; i++)
        {
            res = res * (n - i + 1) / i;
            if (res >= MAX)
                return MAX;
        }

        return res;
    }
}
