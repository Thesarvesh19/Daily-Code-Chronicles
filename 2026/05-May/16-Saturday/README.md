# 154. Find Minimum in Rotated Sorted Array II

## Problem Statement
Given a rotated sorted array `nums` that may contain duplicates, return the minimum element of the array.

You must minimize the overall operation steps as much as possible.

### Example 1:
Input:
nums = [1,3,5]

Output:
1

### Example 2:
Input:
nums = [2,2,2,0,1]

Output:
0

---

## Approach
We use **Binary Search** to reduce the search space.

### Key Observations:
- If `nums[start] < nums[end]`, the current subarray is already sorted, so `nums[start]` is the minimum.
- If `nums[mid] > nums[end]`, minimum lies in the **right half**.
- If `nums[mid] < nums[end]`, minimum lies in the **left half including mid**.
- If duplicates exist (`nums[mid] == nums[end]`), decrease `end` by 1.

This helps handle rotated arrays with repeated values.

---

## C++ Solution

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {

            if (nums[start] < nums[end])
                return nums[start];

            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else if (nums[mid] < nums[end]) {
                end = mid;
            }
            else {
                end--;
            }
        }

        return nums[start];
    }
};
