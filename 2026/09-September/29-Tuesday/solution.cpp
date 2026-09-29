#include <vector>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Quick pruning checks
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        
        // memo[i][j][k] stores whether state (i, j, k) has been solved (-1: unvisited, 0: false, 1: true)
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        
        return dfs(grid, 0, 0, 0, m, n, memo);
    }

private:
    bool dfs(const vector<vector<char>>& grid, int i, int j, int k, int m, int n, vector<vector<vector<int>>>& memo) {
        // Update balance for the current cell
        k += (grid[i][j] == '(') ? 1 : -1;
        
        // Pruning conditions
        if (k < 0 || k > (m - 1 - i) + (n - 1 - j)) {
            return false;
        }
        
        // Base case: Reached bottom-right destination
        if (i == m - 1 && j == n - 1) {
            return k == 0;
        }
        
        // Return cached result if available
        if (memo[i][j][k] != -1) {
            return memo[i][j][k];
        }
        
        // Explore Down and Right paths
        bool isValid = false;
        if (i + 1 < m && dfs(grid, i + 1, j, k, m, n, memo)) {
            isValid = true;
        } else if (j + 1 < n && dfs(grid, i, j + 1, k, m, n, memo)) {
            isValid = true;
        }
        
        return memo[i][j][k] = isValid;
    }
};
