// Minimum Absolute Distance Between Mirror Pairs

import java.util.*;

class Solution {
    public int minMirrorPairDistance(int[] nums) { 
        Map<Integer, Integer> map = new HashMap<>();
        int ans = Integer.MAX_VALUE;

        for (int j = 0; j < nums.length; j++) {
            int num = nums[j];

            if (map.containsKey(num)) {
                ans = Math.min(ans, j - map.get(num));
            }

            int rev = reverse(num);
            map.put(rev, j);
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private int reverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
}
