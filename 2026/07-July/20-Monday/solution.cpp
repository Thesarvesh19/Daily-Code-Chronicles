class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;

        k %= total;

        vector<vector<int>> answer(rows, vector<int>(cols));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                int current = r * cols + c;
                int target = (current + k) % total;

                int nr = target / cols;
                int nc = target % cols;

                answer[nr][nc] = grid[r][c];
            }
        }

        return answer;
    }
};
