using System;
using System.Collections.Generic;

public class Solution
{
    public bool HasValidPath(int[][] grid)
    {
        int rows = grid.Length;
        int cols = grid[0].Length;

        Dictionary<int, int[][]> directions = new Dictionary<int, int[][]>
        {
            {1, new[] { new[] {0, -1}, new[] {0, 1} }},
            {2, new[] { new[] {-1, 0}, new[] {1, 0} }},
            {3, new[] { new[] {0, -1}, new[] {1, 0} }},
            {4, new[] { new[] {0, 1}, new[] {1, 0} }},
            {5, new[] { new[] {0, -1}, new[] {-1, 0} }},
            {6, new[] { new[] {0, 1}, new[] {-1, 0} }}
        };

        Dictionary<string, int[]> opposite = new Dictionary<string, int[]>
        {
            {"0,-1", new[] {0, 1}},
            {"0,1", new[] {0, -1}},
            {"-1,0", new[] {1, 0}},
            {"1,0", new[] {-1, 0}}
        };

        bool[,] visited = new bool[rows, cols];
        Queue<(int, int)> queue = new Queue<(int, int)>();

        queue.Enqueue((0, 0));
        visited[0, 0] = true;

        while (queue.Count > 0)
        {
            var (x, y) = queue.Dequeue();

            if (x == rows - 1 && y == cols - 1)
                return true;

            foreach (var move in directions[grid[x][y]])
            {
                int dx = move[0];
                int dy = move[1];
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                    continue;

                if (visited[nx, ny])
                    continue;

                int[] back = opposite[$"{dx},{dy}"];

                foreach (var next in directions[grid[nx][ny]])
                {
                    if (next[0] == back[0] && next[1] == back[1])
                    {
                        visited[nx, ny] = true;
                        queue.Enqueue((nx, ny));
                        break;
                    }
                }
            }
        }

        return false;
    }
}
