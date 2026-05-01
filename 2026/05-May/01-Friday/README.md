# LeetCode 396 - Rotate Function

##  Problem
Given an integer array `nums`, define:

F(k) = sum of i * arr[i] after rotating the array k times.

Return the maximum value of F(k).

--- 

##  Approach

Instead of recalculating every rotation (O(n²)), we use a recurrence:

F(k) = F(k-1) + sum(nums) - n * nums[n - k]

### Steps:
1. Compute total sum of array
2. Compute F(0)
3. Use recurrence to compute next values efficiently
4. Track maximum result

---

##  Complexity
- Time: O(n)
- Space: O(1)

---

##  Key Insight
Each rotation shifts contribution of elements in a predictable way,
allowing reuse of previous computation.

---

##  Example
Input: [4,3,2,6]

Output: 26

---

##  Files
- solution.java
- solution.py
- solution.cpp

---

##  Status
Optimized and accepted on LeetCode
