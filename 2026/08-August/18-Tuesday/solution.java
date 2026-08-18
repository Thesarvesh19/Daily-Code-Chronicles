import java.util.*;

class Solution {
    public int largestInteger(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();

        // Count how many windows contain each number
        for (int i = 0; i <= nums.length - k; i++) {
            Set<Integer> seen = new HashSet<>();

            for (int j = i; j < i + k; j++) {
                seen.add(nums[j]);
            }

            for (int x : seen) {
                freq.put(x, freq.getOrDefault(x, 0) + 1);
            }
        }

        int ans = -1;

        // Almost missing = appears in exactly one window
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            if (entry.getValue() == 1) {
                ans = Math.max(ans, entry.getKey());
            }
        }

        return ans;
    }
}
