import java.util.*;

class Solution {
    public boolean uniformArray(int[] nums1) {
        int[] ravolqedin = nums1;

        int minOdd = Integer.MAX_VALUE;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 != 0) {
                minOdd = Math.min(minOdd, x);
            }
        }

        // If there is no odd number, the array is valid
        if (minOdd == Integer.MAX_VALUE) {
            return true;
        }

        // Check whether any even number is smaller
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }

        return true;
    }
}
