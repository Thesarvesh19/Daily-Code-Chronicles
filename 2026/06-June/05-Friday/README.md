# LeetCode 3753 - Total Waviness of Numbers in Range II

## Problem

Given two integers `num1` and `num2`, return the total waviness of all numbers in the inclusive range `[num1, num2]`.

A digit is:
 
- Peak if it is strictly greater than both neighbors.
- Valley if it is strictly smaller than both neighbors.
- First and last digits are never considered.
- Numbers having less than 3 digits contribute 0 waviness.

---

## Example

Input:

num1 = 120
num2 = 130

Output:

3

Explanation:

120 -> middle digit 2 is a peak
121 -> middle digit 2 is a peak
130 -> middle digit 3 is a peak

Total = 3

---

## Approach

Brute force is impossible because the range can be very large.

We use Digit Dynamic Programming.

State:

(pos, prev, prev2, leadingZero, tight)

Where:

- pos = current digit position
- prev = previous digit
- prev2 = second previous digit
- leadingZero = still skipping leading zeros
- tight = currently bounded by original number

For every newly chosen digit we can determine whether the previous digit becomes:

- Peak
- Valley
- Neither

The DP returns:

- Count of valid numbers
- Total waviness contributed by those numbers

Finally:

answer = solve(num2) - solve(num1 - 1)

---

## Complexity

Time Complexity:

O(D × 11 × 11 × 2 × 2 × 10)

Where D is number of digits.

Space Complexity:

O(D × 11 × 11 × 2 × 2)

---

## Topics

- Digit DP
- Dynamic Programming
- Memoization
- Hard
