# Minimum Distance to Type a Word Using Two Fingers

## Problem
Compute the minimum distance required to type a word using two fingers on a keyboard grid.

## Approach

- Use dynamic programming with memoization.
- Track positions of both fingers and current index.
- At each step, choose:
  - Move left finger
  - Move right finger
- Take the minimum cost of both options.

## State Definition

dp(i, j, k):
- i = position of left finger
- j = position of right finger
- k = current index in word

## Key Idea

- Use 26 as a virtual starting position (no cost).
- Apply recursion + memoization to avoid recomputation.

## Complexity

- Time: O(n * 27 * 27)
- Space: O(n * 27 * 27)

## Example

Input: "CAKE"  
Output: 3

Input: "HAPPY"  
Output: 6
