/*
 Problem Statement: Minimum Cost Calculation

 You are given an integer array nums, and two integers k and dist.

 Rules:
 - The first element nums[0] is always included in the final cost.
 - From the remaining elements, you must select exactly k - 1 elements.
 - The selected elements must follow a distance constraint defined by dist.
 - The distance constraint limits how far selected elements can be from
   each other in the array.

 Objective:
 - Return the minimum possible total cost, which is the sum of:
   nums[0] and the selected k - 1 elements.

 Input:
 - nums: integer array
 - k: number of elements to include
 - dist: distance constraint

 Output:
 - Returns the minimum possible cost as a long value.

 Note:
 - This solution is optimized for performance using TreeSet.
 - Logic strictly follows the problem constraints.
*/

class Solution {
    public long minimumCost(int[] nums, int k, int dist) {
        int n = nums.length;
        long ans = Long.MAX_VALUE;
        long currSum = 0L;

        TreeSet<Integer> selected = new TreeSet<>(
            (i, j) -> nums[i] == nums[j] ? i - j : nums[i] - nums[j]
        );
        TreeSet<Integer> remaining = new TreeSet<>(
            (i, j) -> nums[i] == nums[j] ? i - j : nums[i] - nums[j]
        );

        for (int i = 1; i < n; i++) {
            selected.add(i);
            currSum += nums[i];

            if (selected.size() >= k) {
                int idx = selected.pollLast();
                currSum -= nums[idx];
                remaining.add(idx);
            }

            if (i - dist > 0) {
                ans = Math.min(ans, currSum);
                int removeIdx = i - dist;

                if (selected.contains(removeIdx)) {
                    selected.remove(removeIdx);
                    currSum -= nums[removeIdx];

                    if (!remaining.isEmpty()) {
                        int addIdx = remaining.pollFirst();
                        selected.add(addIdx);
                        currSum += nums[addIdx];
                    }
                } else {
                    remaining.remove(removeIdx);
                }
            }
        }
        return ans + nums[0];
    }
}
