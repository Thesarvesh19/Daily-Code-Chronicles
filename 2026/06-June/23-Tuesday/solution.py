class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        r -= l  # Normalize range to 0-indexed
        dp = [1] * (r + 1)
        
        for i in range(1, n):
            pre = 0
            if i % 2 == 1:
                # Up: sum of previous values < current value
                for v in range(r + 1):
                    pre2 = pre + dp[v]
                    dp[v] = pre
                    pre = pre2 % MOD
            else:
                # Down: sum of previous values > current value
                for v in range(r, -1, -1):
                    pre2 = pre + dp[v]
                    dp[v] = pre
                    pre = pre2 % MOD
                    
        res = sum(dp) % MOD
        return (res * 2) % MOD
