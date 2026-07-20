public class Solution
{
    public IList<IList<int>> ShiftGrid(int[][] grid, int k)
    {
        int rows = grid.Length;
        int cols = grid[0].Length;
        int total = rows * cols;

        k %= total;

        int[][] shifted = new int[rows][];

        for (int i = 0; i < rows; i++)
            shifted[i] = new int[cols];

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int current = r * cols + c;
                int target = (current + k) % total;

                int nr = target / cols;
                int nc = target % cols;

                shifted[nr][nc] = grid[r][c];
            }
        }

        IList<IList<int>> answer = new List<IList<int>>();

        for (int i = 0; i < rows; i++)
        {
            List<int> row = new List<int>();

            for (int j = 0; j < cols; j++)
                row.Add(shifted[i][j]);

            answer.Add(row);
        }

        return answer;
    }
}
