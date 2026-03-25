class Solution:
    def canPartitionGrid(self, grid):
        m, n = len(grid), len(grid[0])
        
        # Calculate total sum of grid
        total = sum(sum(row) for row in grid)
        
        # If total is odd, cannot split equally
        if total % 2 != 0: 
            return False
        
        target = total // 2
        
        # Check horizontal cuts
        prefix = 0
        for i in range(m - 1):  # ensure both parts are non-empty
            prefix += sum(grid[i])
            if prefix == target:
                return True
        
        # Compute column sums
        col_sums = [0] * n
        for j in range(n):
            for i in range(m):
                col_sums[j] += grid[i][j]
        
        # Check vertical cuts
        prefix = 0
        for j in range(n - 1):  # ensure both parts are non-empty
            prefix += col_sums[j]
            if prefix == target:
                return True
        
        return False
