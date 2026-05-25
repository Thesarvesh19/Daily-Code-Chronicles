# 1871. Jump Game VII

## Problem
Given a binary string `s` and two integers `minJump`
and `maxJump`, determine whether you can reach the last
index starting from index `0`.

---

## Approach
Use Dynamic Programming with a Sliding Window.

- `dp[i] = true` means index `i` is reachable.
- Maintain count of reachable positions within
  `[i-maxJump, i-minJump]`.

This avoids checking all previous positions.

---

## Complexity

Time Complexity:

O(n)

Space Complexity:

O(n)

---

## Example

Input:

s = "011010"
minJump = 2
maxJump = 3

Output:

true

Explanation:

0 → 3 → 5

Reach last index successfully.
