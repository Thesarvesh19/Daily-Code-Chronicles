class Solution:
    def minAbsDiff(self, grid, k):
        m, n = len(grid), len(grid[0])
        ans = []

        for i in range(m - k + 1): 
            row = []
            for j in range(n - k + 1):
                vals = []

                # Collect elements in k x k submatrix
                for x in range(i, i + k):
                    for y in range(j, j + k):
                        vals.append(grid[x][y])

                # Remove duplicates
                vals = list(set(vals))

                # If only one unique element
                if len(vals) == 1:
                    row.append(0)
                    continue

                # Sort unique values
                vals.sort()

                # Find minimum absolute difference
                min_diff = float('inf')
                for t in range(1, len(vals)):
                    min_diff = min(min_diff, vals[t] - vals[t - 1])

                row.append(min_diff)

            ans.append(row)

        return ans
