from typing import List

class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        sums = set()

        # single cells (area 0 rhombus)
        for r in range(m):
            for c in range(n):
                sums.add(grid[r][c])

        # rhombus with size k
        for r in range(m):
            for c in range(n):
                k = 1
                while True:
                    if r-k < 0 or r+k >= m or c-k < 0 or c+k >= n:
                        break

                    total = 0

                    # top -> right
                    x, y = r-k, c
                    for i in range(k):
                        total += grid[x+i][y+i]

                    # right -> bottom
                    x, y = r, c+k
                    for i in range(k):
                        total += grid[x+i][y-i]

                    # bottom -> left
                    x, y = r+k, c
                    for i in range(k):
                        total += grid[x-i][y-i]

                    # left -> top
                    x, y = r, c-k
                    for i in range(k):
                        total += grid[x-i][y+i]

                    sums.add(total)
                    k += 1

        return sorted(sums, reverse=True)[:3]
