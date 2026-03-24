class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        int MOD = 12345;
        int n = grid.length, m = grid[0].length;
        
        int size = n * m;
        int[] arr = new int[size];
        
        // Flatten grid
        int idx = 0;
        for (int[] row : grid) {
            for (int val : row) {
                arr[idx++] = val;
            }
        }
        
        // Prefix
        int[] prefix = new int[size];
        prefix[0] = 1;
        for (int i = 1; i < size; i++) {
            prefix[i] = (int)((long)prefix[i - 1] * arr[i - 1] % MOD);
        }
        
        // Suffix
        int[] suffix = new int[size];
        suffix[size - 1] = 1;
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (int)((long)suffix[i + 1] * arr[i + 1] % MOD);
        }
        
        // Result
        int[] result = new int[size];
        for (int i = 0; i < size; i++) {
            result[i] = (int)((long)prefix[i] * suffix[i] % MOD);
        }
        
        // Convert back to 2D
        int[][] res = new int[n][m];
        idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = result[idx++];
            }
        }
        
        return res;
    }
}
