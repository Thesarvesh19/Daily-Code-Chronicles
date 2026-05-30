from bisect import bisect_right
from sortedcontainers import SortedList

class FenwickTree: 
    def __init__(self, n):
        self.bit = [0] * (n + 1)

    def update(self, idx, val):
        while idx < len(self.bit):
            self.bit[idx] = max(self.bit[idx], val)
            idx += idx & -idx

    def query(self, idx):
        res = 0
        while idx > 0:
            res = max(res, self.bit[idx])
            idx -= idx & -idx
        return res


class Solution:
    def getResults(self, queries):
        limit = min(50000, len(queries) * 3)

        obstacles = SortedList([0, limit])
        bit = FenwickTree(limit + 2)

        for q in queries:
            if q[0] == 1:
                obstacles.add(q[1])

        for i in range(len(obstacles) - 1):
            left = obstacles[i]
            right = obstacles[i + 1]
            bit.update(right, right - left)

        ans = []

        for q in reversed(queries):
            if q[0] == 1:
                x = q[1]

                idx = obstacles.index(x)
                prev_ob = obstacles[idx - 1]
                next_ob = obstacles[idx + 1]

                obstacles.remove(x)
                bit.update(next_ob, next_ob - prev_ob)

            else:
                x, sz = q[1], q[2]

                idx = obstacles.bisect_right(x)
                prev_ob = obstacles[idx - 1]

                ans.append(
                    bit.query(prev_ob) >= sz or
                    x - prev_ob >= sz
                )

        return ans[::-1]
