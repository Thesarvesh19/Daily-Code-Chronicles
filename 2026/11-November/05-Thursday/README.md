# LeetCode 1385 – Find the Distance Value Between Two Arrays

## Problem
Given two integer arrays `arr1` and `arr2`, and an integer `d`, return the distance value between the two arrays.

The distance value is defined as the number of elements `arr1[i]` such that there is no element `arr2[j]` satisfying:

`|arr1[i] - arr2[j]| <= d`

## Approach: Brute Force

1. Initialize a counter `count = 0`.
2. Iterate through every element in `arr1`.
3. For each element, compare it with every element in `arr2`.
4. If the absolute difference is less than or equal to `d`, mark the element as invalid.
5. If no such element exists, increment the counter.
6. Return the final count.

## Python Solution

```python
class Solution:
    def findTheDistanceValue(self, arr1, arr2, d):
        count = 0

        for x in arr1:
            valid = True

            for y in arr2:
                if abs(x - y) <= d:
                    valid = False
                    break

            if valid:
                count += 1

        return count
```

## Example

**Input:**
```text
arr1 = [4, 5, 8]
arr2 = [10, 9, 1, 8]
d = 2
```

**Output:**
```text
2
```

**Explanation:**

- `4`: Valid because no element in `arr2` has an absolute difference less than or equal to 2.
- `5`: Valid for the same reason.
- `8`: Invalid because `8` exists in `arr2`.

Therefore, the distance value is `2`.

## Complexity Analysis

| Complexity | Value |
|---|---|
| Time Complexity | O(n × m) |
| Space Complexity | O(1) |

Where:
- `n` = Length of `arr1`.
- `m` = Length of `arr2`.

## Key Concepts
- Arrays
- Nested Loops
- Absolute Difference
- Conditional Statements
- Brute Force

## Optimization
An alternative approach is to sort `arr2` and use binary search to check whether any element falls within the range `[x - d, x + d]`.

This improves the time complexity to O(m log m + n log m).

---
 Easy

**Language:** Python 3
