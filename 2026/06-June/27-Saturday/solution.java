import java.util.*;

class Solution {
    public int maximumLength(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        int maxNum = 0;
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
            maxNum = Math.max(maxNum, num);
        }
        
        // Handle edge case for 1
        int ans = 1;
        if (count.containsKey(1)) {
            int ones = count.get(1);
            ans = (ones % 2 == 0) ? ones - 1 : ones;
        }
        
        for (int num : count.keySet()) {
            if (num == 1) continue;
            
            int length = 0;
            long x = num; // Use long to prevent integer overflow during squaring
            
            while (x <= maxNum && count.getOrDefault((int)x, 0) >= 2) {
                length += 2;
                x = x * x;
            }
            
            if (x <= maxNum && count.getOrDefault((int)x, 0) >= 1) {
                length += 1;
            } else {
                length -= 1;
            }
            
            ans = Math.max(ans, length);
        }
        
        return ans;
    }
}
