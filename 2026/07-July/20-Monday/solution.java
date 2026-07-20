class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int rows = grid.length;
        int cols = grid[0].length;
        int total = rows * cols;

        k %= total;

        int[][] shifted = new int[rows][cols];

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                int current = r * cols + c;
                int destination = (current + k) % total;

                int nr = destination / cols;
                int nc = destination % cols;

                shifted[nr][nc] = grid[r][c];
            }
        }

        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < rows; i++) {
            List<Integer> row = new ArrayList<>();

            for (int j = 0; j < cols; j++) {
                row.add(shifted[i][j]);
            }

            result.add(row);
        }

        return result;
    }
}
