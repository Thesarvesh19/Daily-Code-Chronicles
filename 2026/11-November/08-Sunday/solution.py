class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row_counts = [0] * m
        col_counts = [0] * n
        
        # First pass: Count servers in each row and column
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    row_counts[i] += 1
                    col_counts[j] += 1
                    
        # Second pass: Count servers that have at least one neighbor in row or column
        communicating_servers = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (row_counts[i] > 1 or col_counts[j] > 1):
                    communicating_servers += 1
                    
        return communicating_servers
