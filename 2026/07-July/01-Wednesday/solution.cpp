#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If start or end contains a thief, return 0
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return 0;
        }
        
        // Step 1: Multi-source BFS
        vector<vector<int>> distToThief(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    distToThief[r][c] = 0;
                }
            }
        }
        
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && distToThief[nr][nc] == -1) {
                    distToThief[nr][nc] = distToThief[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // Step 2: Modified Dijkstra using Max-Heap
        // Priority Queue stores: {safeness_factor, {r, c}}
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        maxHeap.push({distToThief[0][0], {0, 0}});
        visited[0][0] = true;
        
        while (!maxHeap.empty()) {
            auto [currentSafeness, cell] = maxHeap.top();
            maxHeap.pop();
            
            int r = cell.first;
            int c = cell.second;
            
            // Reached destination
            if (r == n - 1 && c == n - 1) {
                return currentSafeness;
            }
            
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int nextSafeness = min(currentSafeness, distToThief[nr][nc]);
                    maxHeap.push({nextSafeness, {nr, nc}});
                }
            }
        }
        
        return 0;
    }
};
