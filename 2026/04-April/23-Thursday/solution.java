// 2615. Sum of Distances

import java.util.*;
 
class Solution {
    public long[] distance(int[] nums) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        
        // Step 1: group indices
        for (int i = 0; i < nums.length; i++) {
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        
        long[] res = new long[nums.length];
        
        // Step 2: process each group
        for (List<Integer> indices : map.values()) {
            int n = indices.size();
            
            long[] prefix = new long[n + 1];
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + indices.get(i);
            }
            
            for (int i = 0; i < n; i++) {
                int idx = indices.get(i);
                
                // left side
                long leftCount = i;
                long leftSum = prefix[i];
                long left = idx * leftCount - leftSum;
                
                // right side
                long rightCount = n - i - 1;
                long rightSum = prefix[n] - prefix[i + 1];
                long right = rightSum - idx * rightCount;
                
                res[idx] = left + right;
            }
        }
        
        return res;
    }
}
