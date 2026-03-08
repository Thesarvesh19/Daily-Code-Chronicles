# Find Unique Binary String

## Problem Description

Given an array of strings `nums` containing `n` **unique binary strings**, each of length `n`, return a **binary string of length `n` that does not appear in `nums`**.

If there are multiple possible answers, you may return **any one of them**.

### Example 1 

Input:

```
nums = ["01","10"]
```

Output:

```
"11"
```

Explanation:
"11" does not appear in `nums`. "00" would also be a valid answer.

### Example 2

Input:

```
nums = ["00","01"]
```

Output:

```
"11"
```

Explanation:
"11" is not present in the given list. "10" would also work.

### Example 3

Input:

```
nums = ["111","011","001"]
```

Output:

```
"101"
```

Explanation:
"101" is not present in the array. Other valid answers include "000", "010", "100", and "110".

---

## Constraints

* `n == nums.length`
* `1 <= n <= 16`
* `nums[i].length == n`
* `nums[i]` consists only of `'0'` and `'1'`
* All strings in `nums` are **unique**

---

## Approach (Cantor's Diagonalization)

A simple and efficient method is based on **Cantor's Diagonal Argument**.

Since we have `n` binary strings each of length `n`, we construct a new string by **flipping the diagonal elements**.

Steps:

1. Iterate through each index `i` from `0` to `n-1`.
2. Check the `i-th` character of the `i-th` string.
3. Flip the bit:

   * If it is `'0'`, change it to `'1'`
   * If it is `'1'`, change it to `'0'`
4. Append the flipped bit to the result string.

This guarantees that the generated string differs from every string in `nums` at least at one position.

---

## Algorithm

1. Initialize an empty result list.
2. Loop through the array indices.
3. Flip the diagonal bit `nums[i][i]`.
4. Append the flipped value to the result.
5. Join the characters to form the final binary string.

---

## Time Complexity

```
O(n)
```

We traverse the array once.

## Space Complexity

```
O(n)
```

To store the resulting binary string.

---

## Python Implementation

```python
class Solution:
    def findDifferentBinaryString(self, nums):
        result = []

        for i in range(len(nums)):
            if nums[i][i] == '0':
                result.append('1')
            else:
                result.append('0')

        return "".join(result)
```

---

## How It Works

Example:

```
nums = ["01", "10"]
```

Step-by-step:

```
nums[0][0] = '0' → flip → '1'
nums[1][1] = '0' → flip → '1'
```

Constructed string:

```
"11"
```

This string differs from:

* `"01"` at index `0`
* `"10"` at index `1`

Therefore it **cannot already exist in the array**.

---

## Summary

* Use **diagonal flipping** to guarantee uniqueness.
* The method is simple, fast, and mathematically guaranteed to work.
* Works efficiently within the problem constraints.

---
