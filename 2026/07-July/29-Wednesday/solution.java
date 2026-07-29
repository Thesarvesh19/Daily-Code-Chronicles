import java.util.*;

class Solution {
    private static final int MAX = 1_000_001;

    public String smallestPalindrome(String s, int k) {
        int[] freq = new int[26];

        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int[] half = new int[26];
        String mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if ((freq[i] & 1) == 1) {
                mid = String.valueOf((char) ('a' + i));
            }
        }

        if (countWays(half) < k) {
            return "";
        }

        StringBuilder left = new StringBuilder();
        int len = 0;
        for (int x : half) len += x;

        for (int pos = 0; pos < len; pos++) {
            for (int i = 0; i < 26; i++) {
                if (half[i] == 0) continue;

                half[i]--;
                int ways = countWays(half);

                if (ways >= k) {
                    left.append((char) ('a' + i));
                    break;
                }

                k -= ways;
                half[i]++;
            }
        }

        StringBuilder ans = new StringBuilder();
        ans.append(left);
        ans.append(mid);
        ans.append(left.reverse());

        return ans.toString();
    }

    private int countWays(int[] cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long res = 1;

        for (int f : cnt) {
            res *= nCk(total, f);
            if (res >= MAX) return MAX;
            total -= f;
        }

        return (int) res;
    }

    private long nCk(int n, int k) {
        k = Math.min(k, n - k);
        long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX) return MAX;
        }

        return res;
    }
}
