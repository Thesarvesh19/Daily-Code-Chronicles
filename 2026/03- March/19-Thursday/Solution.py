class Solution:
    def numberOfSubmatrices(self, grid):
        m, n = len(grid), len(grid[0])
        
        # prefix sums
        prefix_sum = [[0] * (n + 1) for _ in range(m + 1)]
        prefix_x = [[0] * (n + 1) for _ in range(m + 1)]
        
        # build prefix arrays 
        for i in range(m):
            for j in range(n):
                val = 0
                if grid[i][j] == 'X':
                    val = 1
                elif grid[i][j] == 'Y':
                    val = -1
                
                prefix_sum[i+1][j+1] = (
                    val
                    + prefix_sum[i][j+1]
                    + prefix_sum[i+1][j]
                    - prefix_sum[i][j]
                )
                
                prefix_x[i+1][j+1] = (
                    (1 if grid[i][j] == 'X' else 0)
                    + prefix_x[i][j+1]
                    + prefix_x[i+1][j]
                    - prefix_x[i][j]
                )
        
        # count valid submatrices
        ans = 0
        
        for i in range(m):
            for j in range(n):
                if prefix_sum[i+1][j+1] == 0 and prefix_x[i+1][j+1] > 0:
                    ans += 1
        
        return ans
