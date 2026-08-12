class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)

        # suffix[i] = total stones from i to n-1
        suffix = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        # dp(i, M) = maximum stones current player can get
        # starting from index i with current M
        @lru_cache(None)
        def dp(i, M):
            if i >= n:
                return 0

            # Can take all remaining piles
            if 2 * M >= n - i:
                return suffix[i]

            best = 0

            # Take X piles, where 1 <= X <= 2*M
            for x in range(1, 2 * M + 1):
                # Opponent gets dp(i+x, max(M,x))
                # So we take total remaining - opponent's best
                best = max(
                    best,
                    suffix[i] - dp(i + x, max(M, x))
                )

            return best

        return dp(0, 1)
