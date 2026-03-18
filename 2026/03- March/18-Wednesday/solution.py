class Solution:
    def countSubmatrices(self, grid, k):
        m, n = len(grid), len(grid[0])
         
        col_sum = [0] * n
        count = 0
        
        for i in range(m):
            row_prefix = 0
            for j in range(n):
                # accumulate column sum
                col_sum[j] += grid[i][j]
                
                # prefix sum from (0,0) to (i,j)
                row_prefix += col_sum[j]
                
                if row_prefix <= k:
                    count += 1
        
        return count
