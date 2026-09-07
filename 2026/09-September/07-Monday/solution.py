class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        dp = 0
        last = {}

        for ch in s:
            new_dp = (2 * dp + 1) % MOD

            if ch in last:
                new_dp = (new_dp - last[ch]) % MOD

            last[ch] = (dp + 1) % MOD
            dp = new_dp

        return dp
