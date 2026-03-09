class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7
        from functools import lru_cache

        @lru_cache(None)
        def dfs(z, o, last, streak):
            if z == 0 and o == 0:
                return 1

            ans = 0

            if z > 0:
                if last != 0:
                    ans += dfs(z - 1, o, 0, 1)
                elif streak < limit:
                    ans += dfs(z - 1, o, 0, streak + 1)

            if o > 0:
                if last != 1:
                    ans += dfs(z, o - 1, 1, 1)
                elif streak < limit:
                    ans += dfs(z, o - 1, 1, streak + 1)

            return ans % MOD

        return dfs(zero, one, -1, 0)
