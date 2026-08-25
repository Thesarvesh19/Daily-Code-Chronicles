using System;
using System.Collections.Generic;

public class Solution {
    public int MissingMultiple(int[] nums, int k) {
        HashSet<int> set = new HashSet<int>(nums);

        for (int i = 1; ; i++) {
            int x = i * k;

            if (!set.Contains(x)) {
                return x;
            }
        }
    }
}
