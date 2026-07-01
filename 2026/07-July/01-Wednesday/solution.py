from collections import deque
import heapq

class Solution:
    def maximumSafenessFactor(self, grid: list[list[int]]) -> int:
        n = len(grid)
        
        # If the start or end contains a thief, the safeness factor is instantly 0
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return 0
            
        # Step 1: Multi-source BFS to calculate minimum distance to any thief
        dist_to_thief = [[-1] * n for _ in range(n)]
        q = deque()
        
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    q.append((r, c))
                    dist_to_thief[r][c] = 0
                    
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        while q:
            r, c = q.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and dist_to_thief[nr][nc] == -1:
                    dist_to_thief[nr][nc] = dist_to_thief[r][c] + 1
                    q.append((nr, nc))
                    
        # Step 2: Modified Dijkstra using Max-Heap to find maximum safeness path
        # Max-heap elements: (-safeness_factor_of_path, r, c)
        max_heap = [(-dist_to_thief[0][0], 0, 0)]
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True
        
        while max_heap:
            current_safeness, r, c = heapq.heappop(max_heap)
            current_safeness = -current_safeness  # Convert back to positive
            
            # Reached destination
            if r == n - 1 and c == n - 1:
                return current_safeness
                
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                    visited[nr][nc] = True
                    # The safeness of the path to the neighbor is the bottleneck min
                    next_safeness = min(current_safeness, dist_to_thief[nr][nc])
                    heapq.heappush(max_heap, (-next_safeness, nr, nc))
                    
        return 0
