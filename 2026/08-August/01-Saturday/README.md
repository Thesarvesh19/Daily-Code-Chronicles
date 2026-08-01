# 486. Predict the Winner

## Problem

You are given an integer array `nums`, where two players take turns picking a number from either the beginning or the end of the array. Each picked number is added to the player's score.

Both players play optimally.

Return `true` if Player 1 can win or tie the game; otherwise, return `false`.

## Approach

The solution uses **Dynamic Programming with Memoized DFS**.

- Let `dfs(left, right)` represent the maximum score difference the current player can achieve over the opponent from the subarray `nums[left...right]`.
- At each step, the player has two choices:
  - Pick the leftmost number.
  - Pick the rightmost number.
- Since the opponent also plays optimally, subtract the opponent's best possible score difference from the chosen value.
- Store computed results in a memoization table to avoid repeated calculations.
- If the final score difference is non-negative, Player 1 can guarantee at least a tie.

## Algorithm

1. Create a memoization table.
2. Define a recursive function:
   - If only one element remains, return it.
   - Otherwise compute:
     - Pick left.
     - Pick right.
   - Store the maximum result in the memo table.
3. Return whether the computed score difference is at least `0`.

## Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n²)`

## Topics

- Dynamic Programming
- Memoization
- Recursion
- Game Theory
