#include <vector>
#include <deque>

class Solution {
public:
    bool findSafeWalk(std::vector<std::vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, 1e9));
        std::deque<std::pair<int, int>> dq;
        
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                return health - dist[r][c] > 0;
            }
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int w = grid[nr][nc];
                    if (dist[r][c] + w < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + w;
                        if (w == 0) dq.push_front({nr, nc});
                        else dq.push_back({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};
