
# 2243. Calculate Digit Sum of a String

## Problem
You are given a string `s` consisting of digits and an integer `k`.

Repeatedly divide the string into groups of size `k` (the last group may contain fewer than `k` digits). For each group, calculate the sum of its digits and concatenate the sums to form a new string.

Repeat this process until the resulting string contains at most `k` digits. Return the final string.

## Approach: Simulation

1. Continue while the length of `s` is greater than `k`.
2. Divide the string into groups of `k` characters.
3. Calculate the sum of digits in each group.
4. Convert each sum into a string and concatenate the results.
5. Update `s` with the newly generated string.
6. Return `s` when its length becomes at most `k`.

## Python Solution

class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            res = ""

            for i in range(0, len(s), k):
                group = s[i:i + k]
                total = sum(int(digit) for digit in group)
                res += str(total)

            s = res

        return s

## Complexity Analysis

- **Time Complexity:** O(n log_k n), approximately, where n is the length of the string.
- **Space Complexity:** O(n) for storing the intermediate result.

## Example

**Input:**
s = "11111222223", k = 3

**Output:**
"135"

## Key Concepts

- String manipulation
- Simulation
- String slicing
- Digit sum calculation

## LeetCode

[Calculate Digit Sum of a String - LeetCode 2243](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)
