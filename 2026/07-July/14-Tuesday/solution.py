from functools import lru_cache
from math import gcd
from typing import List

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        n = len(nums)

        @lru_cache(None)
        def dfs(index: int, gcd1: int, gcd2: int) -> int:
            if index == n:
                return 1 if gcd1 == gcd2 and gcd1 != 0 else 0

            value = nums[index]

            # Skip current number
            ans = dfs(index + 1, gcd1, gcd2)

            # Put into first subsequence
            next_gcd1 = value if gcd1 == 0 else gcd(gcd1, value)
            ans += dfs(index + 1, next_gcd1, gcd2)

            # Put into second subsequence
            next_gcd2 = value if gcd2 == 0 else gcd(gcd2, value)
            ans += dfs(index + 1, gcd1, next_gcd2)

            return ans % MOD

        return dfs(0, 0, 0)
