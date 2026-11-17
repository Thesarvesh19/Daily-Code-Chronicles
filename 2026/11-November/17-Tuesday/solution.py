class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        INF = float('inf')

        divisors = [[] for _ in range(n + 1)]

        for d in range(1, n + 1):
            for length in range(2 * d, n + 1, d):
                divisors[length].append(d)

        cost = [[0] * (n + 1) for _ in range(n)]

        for i in range(n):
            for j in range(i + 1, n):
                length = j - i + 1
                best = INF

                for d in divisors[length]:
                    changes = 0

                    for r in range(d):
                        left = i + r
                        right = j - ((length - 1 - r) // d) * d

                        while left < right:
                            if s[left] != s[right]:
                                changes += 1
                            left += d
                            right -= d

                    best = min(best, changes)

                cost[i][j + 1] = best

        dp = [[INF] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(1, n + 1):
            for parts in range(1, min(k, i // 2) + 1):
                for j in range(i - 1, parts * 2 - 2, -1):
                    if j == 0 and parts == 1:
                        dp[i][parts] = min(dp[i][parts], 0)
                    elif j > 0:
                        dp[i][parts] = min(
                            dp[i][parts],
                            dp[j][parts - 1] + cost[j][i]
                        )

        return dp[n][k]
