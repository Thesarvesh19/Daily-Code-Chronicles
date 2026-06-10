import java.util.PriorityQueue;

class Solution {
    public long maxTotalValue(int[] nums, int k) {
        int n = nums.length;
        
        int[] log2 = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            log2[i] = log2[i / 2] + 1;
        }
        
        int maxK = log2[n] + 1;
        int[][] maxST = new int[n][maxK];
        int[][] minST = new int[n][maxK];
        
        for (int i = 0; i < n; i++) {
            maxST[i][0] = nums[i];
            minST[i][0] = nums[i];
        }
        
        for (int j = 1; j < maxK; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                maxST[i][j] = Math.max(maxST[i][j - 1], maxST[i + (1 << (j - 1))][j - 1]);
                minST[i][j] = Math.min(minST[i][j - 1], minST[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(b[0], a[0]));
        
        for (int l = 0; l < n; l++) {
            long val = getRangeValue(l, n - 1, maxST, minST, log2);
            pq.offer(new long[]{val, l, n - 1});
        }
        
        long totalSum = 0;
        
        for (int i = 0; i < k; i++) {
            long[] top = pq.poll();
            totalSum += top[0];
            
            int l = (int) top[1];
            int r = (int) top[2];
            
            if (r > l) {
                int nextR = r - 1;
                long nextVal = getRangeValue(l, nextR, maxST, minST, log2);
                pq.offer(new long[]{nextVal, l, nextR});
            }
        }
        
        return totalSum;
    }
    
    private long getRangeValue(int l, int r, int[][] maxST, int[][] minST, int[] log2) {
        int len = r - l + 1;
        int j = log2[len];
        
        int max = Math.max(maxST[l][j], maxST[r - (1 << j) + 1][j]);
        int min = Math.min(minST[l][j], minST[r - (1 << j) + 1][j]);
        
        return (long) max - min;
    }
}
