import java.util.*;

class Solution {

    private final int[][][] directions = {
            {},
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}}
    };

    public boolean hasValidPath(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();

        queue.offer(new int[]{0, 0});
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];

            if (x == rows - 1 && y == cols - 1)
                return true;

            for (int[] dir : directions[grid[x][y]]) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                    continue;

                if (visited[nx][ny])
                    continue;

                int backX = -dir[0];
                int backY = -dir[1];

                for (int[] rev : directions[grid[nx][ny]]) {
                    if (rev[0] == backX && rev[1] == backY) {
                        visited[nx][ny] = true;
                        queue.offer(new int[]{nx, ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
}
