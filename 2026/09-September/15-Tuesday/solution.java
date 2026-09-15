class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        int[] dp = new int[n + 1];

        for (int center = 0; center < n; center++) {

            // Odd-length palindromes
            int l = center;
            int r = center;

            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = Math.max(dp[r + 1], dp[l] + 1);
                }

                l--;
                r++;
            }

            // Even-length palindromes
            l = center;
            r = center + 1;

            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = Math.max(dp[r + 1], dp[l] + 1);
                }

                l--;
                r++;
            }
        }

        // We can skip the current character.
        for (int i = 1; i <= n; i++) {
            dp[i] = Math.max(dp[i], dp[i - 1]);
        }

        return dp[n];
    }
}
