# LeetCode 2913: Subarrays Distinct Element Sum of Squares I

## Problem Description
Given an integer array `nums`, calculate the sum of the squares of the number of distinct elements in every possible subarray.

For each subarray:
1. Count the distinct elements.
2. Square the count.
3. Add the result to the final answer.

## Example

**Input:**
```text
nums = [1, 2, 1]
```

**Output:**
```text
15
```

**Explanation:**

The subarrays are `[1]`, `[1,2]`, `[1,2,1]`, `[2]`, `[2,1]`, and `[1]`.

Their squared distinct counts are `1, 4, 4, 1, 4, 1`.

Therefore, the total sum is `15`.

## Approach
Use two nested loops to generate every possible subarray. For each starting index, maintain a set of distinct elements and extend the subarray one element at a time. After adding each element, calculate the square of the set's size and add it to the answer.

## Python Solution
```python
from typing import List

class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)

        for i in range(n):
            s = set()
            for j in range(i, n):
                s.add(nums[j])
                ans += len(s) ** 2

        return ans
```

## Kotlin Solution
```kotlin
class Solution {
    fun sumCounts(nums: List<Int>): Int {
        var ans = 0
        val n = nums.size

        for (i in 0 until n) {
            val s = mutableSetOf<Int>()

            for (j in i until n) {
                s.add(nums[j])
                ans += s.size * s.size
            }
        }

        return ans
    }
}
```

## C Solution
```c
int sumCounts(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int seen[101] = {0};
        int distinct = 0;

        for (int j = i; j < numsSize; j++) {
            if (!seen[nums[j]]) {
                seen[nums[j]] = 1;
                distinct++;
            }

            ans += distinct * distinct;
        }
    }

    return ans;
}
```

## Complexity Analysis
- **Time Complexity:** `O(n²)` expected for the Python and Kotlin solutions; `O(n²)` for the C solution.
- **Space Complexity:** `O(n)` for Python and Kotlin sets; `O(1)` for C, assuming the elements are in the range `1` to `100`.

## Key Concepts
- Arrays
- Subarrays
- Hash sets
- Nested loops
- Distinct element counting

## Conclusion
This solution efficiently checks every subarray and maintains its distinct element count, giving an `O(n²)` solution suitable for the problem's constraints.
