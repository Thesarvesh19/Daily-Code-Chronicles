# 877. Stone Game

## Problem
Alice and Bob play a game by taking one pile of stones from either end of the row on each turn. Both play optimally. Return `true` if Alice wins the game.

## Approach
For this problem, Alice (the first player) can always guarantee a win by choosing the parity (even-indexed or odd-indexed piles) with the larger total number of stones. Hence, the answer is always `true`.

## Complexity
- **Time:** `O(1)`
- **Space:** `O(1)`

