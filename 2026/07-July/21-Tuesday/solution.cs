public class Solution {
    public int MaxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        int prevZero = 0;
        int best = 0;
        int n = s.Length;

        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;

            int len = j - i;

            if (s[i] == '1')
                ones += len;
            else {
                best = Math.Max(best, prevZero + len);
                prevZero = len;
            }

            i = j;
        }

        return ones + best;
    }
}
