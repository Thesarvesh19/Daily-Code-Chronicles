from functools import lru_cache
from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        @lru_cache(None)
        def dp(i):
            if i >= n:
                return 0

            best = float("-inf")
            total = 0

            for j in range(i, min(i + 3, n)):
                total += stoneValue[j]
                best = max(best, total - dp(j + 1))

            return best

        diff = dp(0)

        if diff > 0:
            return "Alice"
        elif diff < 0:
            return "Bob"
        return "Tie"
