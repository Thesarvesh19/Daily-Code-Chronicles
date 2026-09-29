from functools import cache
from typing import List

class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        # Initial quick pruning checks
        if (m + n - 1) % 2 != 0 or grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False
            
        @cache
        def dfs(i: int, j: int, k: int) -> bool:
            # Update balance for the current cell
            k += 1 if grid[i][j] == '(' else -1
            
            # Pruning conditions:
            # 1. More ')' than '(' encountered
            # 2. More open '(' left than remaining cells to close them
            if k < 0 or k > (m - 1 - i) + (n - 1 - j):
                return False
                
            # Base case: Reached the bottom-right destination
            if i == m - 1 and j == n - 1:
                return k == 0
                
            # Explore Down and Right paths
            if i + 1 < m and dfs(i + 1, j, k):
                return True
            if j + 1 < n and dfs(i, j + 1, k):
                return True
                
            return False

        return dfs(0, 0, 0)
