/** 
 * Problem Statement:
 *
 * You are given an integer array `nums` of length `n`.
 * A trionic subarray is a contiguous subarray that can be divided into
 * three consecutive parts:
 *
 * 1. A strictly increasing sequence
 * 2. A strictly decreasing sequence
 * 3. A strictly increasing sequence
 *
 * The subarray must contain at least one element in each part.
 *
 * Task:
 * Return the maximum possible sum of any trionic subarray.
 * If no such subarray exists, return the minimum possible long value.
 *
 * Approach:
 * - Traverse the array and identify increasing, decreasing, and increasing phases.
 * - Once a valid trionic structure is found, compute:
 *   • Base sum of the core sequence
 *   • Best extendable sum on the left
 *   • Best extendable sum on the right
 * - Track and update the maximum sum encountered.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
    public long maxSumTrionic(int[] nums) {
        int n = nums.length;
        long answer = Long.MIN_VALUE;
        int index = 0;

        while (index < n) {
            int left = index;
            index++;

            // Phase 1: strictly increasing
            while (index < n && nums[index] > nums[index - 1]) {
                index++;
            }
            if (index - left <= 1) {
                continue;
            }

            int peak = index - 1;
            long total = nums[peak] + nums[peak - 1];

            // Phase 2: strictly decreasing
            while (index < n && nums[index] < nums[index - 1]) {
                total += nums[index];
                index++;
            }
            if (index == peak + 1 || index == n || nums[index] == nums[index - 1]) {
                continue;
            }

            int valley = index - 1;

            // Phase 3: strictly increasing
            total += nums[index];
            index++;

            long rightMax = 0, rightSum = 0;
            while (index < n && nums[index] > nums[index - 1]) {
                rightSum += nums[index];
                rightMax = Math.max(rightMax, rightSum);
                index++;
            }
            total += rightMax;

            // Extend from left side
            long leftMax = 0, leftSum = 0;
            for (int i = peak - 2; i >= left; i--) {
                leftSum += nums[i];
                leftMax = Math.max(leftMax, leftSum);
            }
            total += leftMax;

            answer = Math.max(answer, total);
            index = valley;
        }

        return answer;
    }
}
