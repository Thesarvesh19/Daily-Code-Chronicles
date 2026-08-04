import java.util.*;

class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int lo = Integer.MAX_VALUE;
        int hi = Integer.MIN_VALUE;

        Set<Integer> seen = new HashSet<>();
        for (int x : nums) {
            lo = Math.min(lo, x);
            hi = Math.max(hi, x);
            seen.add(x);
        }

        List<Integer> ans = new ArrayList<>();
        for (int x = lo + 1; x < hi; x++) {
            if (!seen.contains(x)) {
                ans.add(x);
            }
        }

        return ans;
    }
}
