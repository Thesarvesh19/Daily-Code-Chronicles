using System.Collections.Generic;

public class Solution {
    public bool FindSafeWalk(IList<IList<int>> grid, int health) {
        int m = grid.Count, n = grid[0].Count;
        int[,] dist = new int[m, n];
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dist[i, j] = int.MaxValue;
                
        int[][] dirs = new int[][] {
            new int[] {0, 1}, new int[] {1, 0}, 
            new int[] {0, -1}, new int[] {-1, 0}
        };
        
        LinkedList<(int, int)> deque = new LinkedList<(int, int)>();
        
        dist[0, 0] = grid[0][0];
        deque.AddFirst((0, 0));
        
        while (deque.Count > 0) {
            var curr = deque.First.Value;
            deque.RemoveFirst();
            int r = curr.Item1, c = curr.Item2;
            
            if (r == m - 1 && c == n - 1) return health - dist[r, c] > 0;
            
            foreach (var dir in dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int w = grid[nr][nc];
                    if (dist[r, c] + w < dist[nr, nc]) {
                        dist[nr, nc] = dist[r, c] + w;
                        if (w == 0) deque.AddFirst((nr, nc));
                        else deque.AddLast((nr, nc));
                    }
                }
            }
        }
        return false;
    }
}
