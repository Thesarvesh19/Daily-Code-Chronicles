# Transformed Circular Array

## Problem
You are given an integer array `nums` that represents a **circular array**.

For each index `i`:
- If `nums[i] > 0` → move `nums[i]` steps to the **right**
- If `nums[i] < 0` → move `abs(nums[i])` steps to the **left**
- If `nums[i] == 0` → stay at the same index

Because the array is circular, moving past the end wraps to the beginning and vice-versa.

Return a new array where each position contains the value at the final landing index.

---

## Example

**Input**
nums = [3, -2, 1, 1]


**Output**
[1, 1, 1, 3]


---

## Approach
- Loop through each index
- Calculate the new index using modulo (`%`) for circular movement
- Fix negative indices
- Store the landed value in the result array

---

## Java Solution

```java
class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                int newIndex = (i + nums[i]) % n;
                if (newIndex < 0) {
                    newIndex += n;
                }
                result[i] = nums[newIndex];
            }
        }
        return result;
    }
}
Python Solution
class Solution:
    def constructTransformedArray(self, nums):
        n = len(nums)
        result = [0] * n

        for i in range(n):
            if nums[i] == 0:
                result[i] = 0
            else:
                new_index = (i + nums[i]) % n
                result[i] = nums[new_index]

        return result
Complexity
Time: O(n)

Space: O(n)

