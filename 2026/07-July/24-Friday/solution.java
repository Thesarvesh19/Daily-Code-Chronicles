import java.util.HashSet;
import java.util.Set;

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;

        if (n == 1)
            return 1;

        Set<Integer> pairXors = new HashSet<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXors.add(nums[i] ^ nums[j]);
            }
        }

        Set<Integer> tripletXors = new HashSet<>();

        for (int px : pairXors) {
            for (int value : nums) {
                tripletXors.add(px ^ value);
            }
        }

        return tripletXors.size();
    }
}
