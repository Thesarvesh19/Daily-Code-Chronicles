import java.util.*;

class Solution {
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length, n = grid[0].length; 

        int[][][] d = {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };

        boolean[][] vis = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0,0});
        vis[0][0] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];

            if (x == m - 1 && y == n - 1) return true;

            for (int[] dir : d[grid[x][y]]) {
                int nx = x + dir[0], ny = y + dir[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
                    for (int[] back : d[grid[nx][ny]]) {
                        if (nx + back[0] == x && ny + back[1] == y) {
                            vis[nx][ny] = true;
                            q.offer(new int[]{nx, ny});
                            break;
                        }
                    }
                }
            }
        }

        return false;
    }
}
