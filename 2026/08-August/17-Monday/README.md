# LeetCode 1563 - Stone Game V

## Problem

Alice and Bob play a game with an array `stoneValue`.

Alice starts the game. On each turn, Alice divides the array into two non-empty parts:

- Left part: `stoneValue[l...k]`
- Right part: `stoneValue[k+1...r]`

Let the sums of the two parts be `leftSum` and `rightSum`.

- If `leftSum < rightSum`, Alice scores `leftSum` and continues with the left part.
- If `leftSum > rightSum`, Alice scores `rightSum` and continues with the right part.
- If `leftSum == rightSum`, Alice scores that sum and can continue with either part.

The goal is to maximize Alice's total score.

---

## Approach

We use **Interval Dynamic Programming**.

### DP Definition

`dp[l][r]` represents the maximum score Alice can obtain from the subarray:

```text
stoneValue[l...r]
