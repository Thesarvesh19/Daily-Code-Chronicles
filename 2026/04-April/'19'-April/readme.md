# 1855. Maximum Distance Between a Pair of Values

## Problem
You are given two non-increasing arrays `nums1` and `nums2`.

A pair `(i, j)` is valid if:
- `i <= j`
- `nums1[i] <= nums2[j]`

The distance of the pair is `j - i`.

Return the maximum distance among all valid pairs. If none exist, return 0.

---

## Approach (Two Pointers)

Since both arrays are non-increasing, we can efficiently use a two-pointer approach:

- Start with `i = 0`, `j = 0`
- If `nums1[i] <= nums2[j]`, it is a valid pair:
  - Update answer with `j - i`
  - Move `j` forward to maximize distance
- Otherwise:
  - Move `i` forward to try a smaller value

---

## Algorithm
1. Initialize `i = 0`, `j = 0`, `ans = 0`
2. While both pointers are within bounds:
   - If `nums1[i] <= nums2[j]`:
     - Update `ans = max(ans, j - i)`
     - Increment `j`
   - Else:
     - Increment `i`
3. Return `ans`

---

## Complexity

- Time Complexity: `O(n + m)`
- Space Complexity: `O(1)`

---

## Example

Input:
nums1 = [55,30,5,4,2]  
nums2 = [100,20,10,10,5]

Output:
2

Explanation:
The maximum distance is achieved at pair `(2, 4)`.

---

## Code (Python)

```python
class Solution:
    def maxDistance(self, nums1, nums2):
        i = j = 0
        ans = 0
        
        while i < len(nums1) and j < len(nums2):
            if nums1[i] <= nums2[j]:
                ans = max(ans, j - i)
                j += 1
            else:
                i += 1
        
        return ans
