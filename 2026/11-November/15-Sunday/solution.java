class Solution {
    public int numOfSubarrays(int[] arr) {
        int MOD = 1_000_000_007;
        
        // cnt[0] counts even prefix sums, cnt[1] counts odd prefix sums
        // Initialize cnt[0] = 1 for the base case (prefix sum of 0)
        int[] cnt = new int[] {1, 0};
        int prefixSum = 0;
        int ans = 0;
        
        for (int x : arr) {
            prefixSum += x;
            int parity = prefixSum % 2;
            
            // Add the count of prefix sums with the opposite parity
            ans = (ans + cnt[1 - parity]) % MOD;
            
            // Record the current prefix sum parity
            cnt[parity]++;
        }
        
        return ans;
    }
}
