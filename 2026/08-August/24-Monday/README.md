# LeetCode 1872 - Stone Game VIII

## Problem

Alice and Bob play a game with an array `stones`.

- Alice starts the game.
- On each turn, a player must take the first `x` stones where `x >= 2`.
- These stones are replaced by a single stone whose value is their sum.
- The player who makes the move adds the value of the resulting stone to their score.
- Both players play optimally.
- Return the final score difference `Alice - Bob`.

## Approach

The key observation is that after taking the first `x` stones, the resulting value is the **prefix sum** of those stones.

Let:

```text
prefix[i] = stones[0] + stones[1] + ... + stones[i]
