# LeetCode 3751 - Total Waviness of Numbers in Range I

## Problem Statement

Given two integers `num1` and `num2`, calculate the total waviness of all numbers in the inclusive range `[num1, num2]`.

A digit is considered **wavy** if it is either:

- Greater than both of its adjacent digits (Peak)
- Smaller than both of its adjacent digits (Valley)

Only digits having both left and right neighbors can contribute to waviness.

---

## Example

Input:

num1 = 120
num2 = 123

Output:

1

Explanation:

120 → digit 2 is greater than 1 and 0 → waviness = 1

121 → digit 2 is greater than 1 and 1 → waviness = 1

122 → no peak or valley → waviness = 0

123 → increasing sequence → waviness = 0

Total = 2

---

## Approach

For every number in the range:

1. Convert the number into a string.
2. Iterate through all middle digits.
3. Check whether the current digit forms:
   - A peak
   - A valley
4. Count all such occurrences.
5. Add the count to the final answer.

Since the maximum number is only `100000`, a direct brute-force solution is sufficient.

---

## Algorithm

For each number:

- Convert number to string.
- For every position `i` from `1` to `length - 2`:
  - If

    digit[i] > digit[i-1] and digit[i] > digit[i+1]

    OR

    digit[i] < digit[i-1] and digit[i] < digit[i+1]

    then increase waviness count.

- Add the waviness of the current number to the answer.

---

## Correctness

A digit contributes to waviness exactly when it forms a local maximum or local minimum among its immediate neighbors.

The algorithm examines every eligible digit once and counts every valid peak and valley exactly once.

Therefore, the computed sum equals the total waviness of all numbers in the range.

---

## Complexity Analysis

Let:

- N = num2 - num1 + 1
- D = maximum number of digits

For this problem:

D ≤ 6

Time Complexity:

O(N × D)

Space Complexity:

O(1)

---

## Languages Implemented

- C++
- Java
- Python
- C#

All implementations follow the same brute-force strategy and satisfy the problem constraints.
