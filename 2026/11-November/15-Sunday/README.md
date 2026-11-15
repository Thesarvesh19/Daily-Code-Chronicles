LeetCode 1524: Number of Sub-arrays With Odd Sum

This repository contains optimal solutions for LeetCode 1524: Number of Sub-arrays With Odd Sum, implemented in both Python and Java.

📋 Problem Description

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo $10^9 + 7$.

Example

Input: arr = [1,3,5]

Output: 4

Explanation: All subarrays are [1], [3], [5], [1,3], [3,5], [1,3,5].

Sums are 1, 3, 5, 4, 8, 9.

The odd sums are 1, 3, 5, 9. Total = 4.

💡 Approach & Intuition

A subarray sum from index $i$ to $j$ can be expressed as the difference between prefix sums: prefix_sum[j] - prefix_sum[i-1].

For the difference to be odd, one of the prefix sums must be even and the other must be odd.

As we iterate through the array, we maintain a frequency count of the prefix sum parities seen so far (cnt[0] for even, cnt[1] for odd).

We initialize cnt[0] = 1 to account for the base case where the prefix sum is 0 (even) before processing any elements.

At each step, if the current prefix sum parity is parity, we add cnt[1 - parity] (the count of opposite parities) to our total answer.

🛠️ Implementations

Python Solution

class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        MOD = 10**9 + 7
        
        # cnt[0] counts even prefix sums, cnt[1] counts odd prefix sums
        cnt = [1, 0]
        prefix_sum = 0
        ans = 0
        
        for x in arr:
            prefix_sum += x
            parity = prefix_sum % 2
            
            # Add the count of prefix sums with the opposite parity
            ans = (ans + cnt[1 - parity]) % MOD
            
            # Record the current prefix sum parity
            cnt[parity] += 1
            
        return ans


Java Solution

class Solution {
    public int numOfSubarrays(int[] arr) {
        int MOD = 1_000_000_007;
        
        // cnt[0] counts even prefix sums, cnt[1] counts odd prefix sums
        int[] cnt = new int[] {1, 0};
        int prefixSum = 0;
        int ans = 0;
        
        for (int x : arr) {
            prefixSum += x;
            int parity = prefixSum % 2;
            
            // Add the count of prefix sums with the opposite parity
            ans = (ans + cnt[1 - parity]) % MOD;
            
            // Record the current prefix sum parity
            cnt[parity]++;
        }
        
        return ans;
    }
}


📊 Complexity Analysis

Time Complexity: $\mathcal{O}(n)$, where $n$ is the length of the input array arr. We iterate through the array exactly once.

Space Complexity: $\mathcal{O}(1)$, as we only use a few constant variables and a fixed-size array/list of length 2 to track prefix sum parities.
