from bisect import bisect_right
from functools import lru_cache

class Solution:
    def maximumWeight(self, intervals):
        n = len(intervals)

        # Store: (start, end, weight, original_index)
        arr = [
            (s, e, w, i)
            for i, (s, e, w) in enumerate(intervals)
        ]

        # Sort by start, then end, then original index
        arr.sort()

        starts = [x[0] for x in arr]

        # next[i] = first interval that starts after arr[i]'s end
        nxt = [0] * n

        for i in range(n):
            nxt[i] = bisect_right(starts, arr[i][1])

        @lru_cache(None)
        def dp(i, k):
            if i >= n or k == 0:
                return (0, ())

            # Option 1: skip current interval
            score1, indices1 = dp(i + 1, k)

            # Option 2: take current interval
            score2, indices2 = dp(nxt[i], k - 1)
            score2 += arr[i][2]

            candidate = tuple(sorted(indices2 + (arr[i][3],)))

            if score2 > score1:
                return score2, candidate

            if score2 < score1:
                return score1, indices1

            # Same score -> lexicographically smaller indices
            return score1, min(indices1, candidate)

        return list(dp(0, 4)[1])
