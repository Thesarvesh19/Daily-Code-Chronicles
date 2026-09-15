class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // isPal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of non-overlapping
        // palindromes using the first i characters
        vector<int> dp(n + 1, 0);

        for (int end = 1; end <= n; end++) {
            // Skip current character
            dp[end] = dp[end - 1];

            // Try every palindrome ending at end - 1
            for (int start = 0; start <= end - k; start++) {
                if (isPal[start][end - 1]) {
                    dp[end] = max(dp[end], dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};
