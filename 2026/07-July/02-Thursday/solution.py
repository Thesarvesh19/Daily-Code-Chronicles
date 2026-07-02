from collections import deque
from typing import List

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        # Track minimum health lost to reach each cell
        dist = [[float('inf')] * n for _ in range(m)]
        
        queue = deque([(0, 0)])
        dist[0][0] = grid[0][0]
        
        while queue:
            r, c = queue.popleft()
            
            if r == m - 1 and c == n - 1:
                return health - dist[r][c] > 0
                
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < m and 0 <= nc < n:
                    weight = grid[nr][nc]
                    
                    if dist[r][c] + weight < dist[nr][nc]:
                        dist[nr][nc] = dist[r][c] + weight
                        
                        # 0-1 BFS appending logic
                        if weight == 0:
                            queue.appendleft((nr, nc))
                        else:
                            queue.append((nr, nc))
                            
        return False
