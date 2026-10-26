class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                stack<pair<int, int>> st;
                st.push({i, j});

                long long total = 0;
                total += grid[i][j];
                grid[i][j] = 0;

                while (!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < m &&
                            ny >= 0 && ny < n &&
                            grid[nx][ny] > 0) {

                            total += grid[nx][ny];
                            grid[nx][ny] = 0;
                            st.push({nx, ny});
                        }
                    }
                }

                if (total % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
