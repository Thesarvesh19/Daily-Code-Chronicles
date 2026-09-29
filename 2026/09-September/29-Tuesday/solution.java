class Solution {
    public boolean hasValidPath(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Quick pruning checks
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        
        // dp[i][j][k] to memoize visited states to avoid redundant calculations.
        // Max balance k cannot exceed m + n - 1.
        Boolean[][][] memo = new Boolean[m][n, (m + n)];
        
        return dfs(grid, 0, 0, 0, m, n, memo);
    }
    
    private boolean dfs(char[][] grid, int i, int j, int k, int m, int n, Boolean[][][] memo) {
        // Update balance for current cell
        k += (grid[i][j] == '(') ? 1 : -1;
        
        // Pruning conditions
        if (k < 0 || k > (m - 1 - i) + (n - 1 - j)) {
            return false;
        }
        
        // Base case: Reached bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return k == 0;
        }
        
        // Return cached result if already computed
        if (memo[i][j][k] != null) {
            return memo[i][j][k];
        }
        
        // Explore Down and Right paths
        boolean isValid = false;
        if (i + 1 < m && dfs(grid, i + 1, j, k, m, n, memo)) {
            isValid = true;
        } else if (j + 1 < n && dfs(grid, i, j + 1, k, m, n, memo)) {
            isValid = true;
        }
        
        return memo[i][j][k] = isValid;
    }
}
