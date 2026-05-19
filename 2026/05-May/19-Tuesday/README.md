# 2540. Minimum Common Value

## Problem Statement
You are given two **sorted** integer arrays `nums1` and `nums2`.

Return the **smallest integer** that appears in **both arrays**. If there is no common integer, return `-1`.

### Example 1:
Input:
nums1 = [1,2,3]
nums2 = [2,4]

Output:
2

Explanation:
2 exists in both arrays and is the minimum common value.

### Example 2:
Input:
nums1 = [1,2,3,6]
nums2 = [2,3,4,5]

Output:
2

---

# Approach (Two Pointer Method)

Since both arrays are already **sorted**, we can use two pointers.

### Steps:
1. Start pointer `i = 0` for `nums1`
2. Start pointer `j = 0` for `nums2`
3. Compare values:
   - If equal → return value
   - If nums1[i] < nums2[j] → move `i`
   - Else move `j`
4. If loop ends → no common element → return `-1`

### Time Complexity:
O(n + m)

### Space Complexity:
O(1)

---

# C++ Solution

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] == nums2[j])
                return nums1[i];

            if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }

        return -1;
    }
};
