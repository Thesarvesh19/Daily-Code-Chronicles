class Solution:
    def reverseSubmatrix(self, grid, x, y, k):
        # Iterate over half the rows of the submatrix
        for i in range(k // 2):
            for j in range(y, y + k):
                # Swap vertically
                grid[x + i][j], grid[x + k - 1 - i][j] = (
                    grid[x + k - 1 - i][j],
                    grid[x + i][j],
                )
        
        return grid
 
