class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        
        int[] colSum = new int[n];
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            int rowPrefix = 0;
            
            for (int j = 0; j < n; j++) {
                // accumulate column sum
                colSum[j] += grid[i][j];
                
                // prefix sum from (0,0) to (i,j)
                rowPrefix += colSum[j];
                
                if (rowPrefix <= k) {
                    count++;
                }
            }
        }
        
        return count;
    }
}
