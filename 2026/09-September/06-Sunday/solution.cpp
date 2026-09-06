class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (char ch : s) {
            for (int j = n - 1; j >= 0; j--) {
                if (ch == t[j]) {
                    dp[j + 1] += dp[j];
                }
            }
        }

        return (int)dp[n];
    }
};
