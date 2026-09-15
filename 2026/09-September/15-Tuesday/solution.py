class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)

        # dp[i] = maximum number of valid non-overlapping
        # palindromes using the first i characters.
        dp = [0] * (n + 1)

        # Expand around every possible center.
        for center in range(n):
            # Odd-length palindrome
            l = r = center
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 >= k:
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1)
                l -= 1
                r += 1

            # Even-length palindrome
            l, r = center, center + 1
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 >= k:
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1)
                l -= 1
                r += 1

        # Carry forward the best answer when we don't
        # end a palindrome at position i.
        for i in range(1, n + 1):
            dp[i] = max(dp[i], dp[i - 1])

        return dp[n]
