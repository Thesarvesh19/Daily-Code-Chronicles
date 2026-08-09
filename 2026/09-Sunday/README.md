# LeetCode 1140 - Stone Game II

## Problem

Alice and Bob play a game with piles of stones.

* Alice starts the game.
* Initially, `M = 1`.
* On each turn, a player can take between `1` and `2 * M` piles.
* After taking `X` piles, `M` becomes `max(M, X)`.
* Both players play optimally.
* Return the maximum number of stones Alice can collect.

## Approach

Use **Dynamic Programming + Suffix Sum**.

Let:

```text
dp(i, M)
```

represent the maximum number of stones the current player can obtain starting from index `i` with the current value of `M`.

For every possible number of piles `X` that can be taken:

```text
1 <= X <= 2 * M
```

the opponent gets:

```text
dp(i + X, max(M, X))
```

Therefore, the current player's maximum score is:

```text
suffix[i] - opponent
```

where `suffix[i]` represents the total number of stones remaining from index `i`.

If the player can take all remaining piles:

```text
2 * M >= n - i
```

then the answer is simply:

```text
suffix[i]
```

## Complexity

* **Time:** `O(n³)`
* **Space:** `O(n²)`

## Example

### Input

```text
piles = [2,7,9,4,4]
```

### Output

```text
10
```

Alice can collect a maximum of `10` stones when both players play optimally.

## Key Concept

The main idea is to calculate the **best score the current player can obtain**, assuming the opponent also plays optimally.

```text
Current Player Score
= Total Remaining Stones - Opponent's Best Score
```
