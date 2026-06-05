from functools import lru_cache

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:

        def solve(x):
            if x <= 0:
                return 0

            s = str(x)

            @lru_cache(None)
            def dfs(pos, prev, prev2, lead, tight):

                if pos == len(s):
                    return (1, 0)

                limit = int(s[pos]) if tight else 9

                cnt = 0
                wav = 0

                for d in range(limit + 1):

                    ntight = tight and d == limit
                    nlead = lead and d == 0

                    sub_cnt, sub_wav = dfs(
                        pos + 1,
                        -1 if nlead else d,
                        prev,
                        nlead,
                        ntight
                    )

                    cnt += sub_cnt

                    if (not lead and
                        prev2 != -1 and
                        ((prev2 < prev and prev > d) or
                         (prev2 > prev and prev < d))):
                        wav += sub_cnt

                    wav += sub_wav

                return (cnt, wav)

            return dfs(0, -1, -1, True, True)[1]

        return solve(num2) - solve(num1 - 1)
