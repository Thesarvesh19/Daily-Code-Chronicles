# Furthest Point From Origin

## Problem

You are given a string `moves` of length `n` consisting only of characters `'L'`, `'R'`, and `'_'`. The string represents your movement on a number line starting from the origin `0`.

In the `i-th` move, you can choose one of the following directions:

- Move to the left if `moves[i] = 'L'` or `moves[i] = '_'`
- Move to the right if `moves[i] = 'R'` or `moves[i] = '_'`

Return the **maximum distance from the origin** that can be achieved after performing all moves.

---

## Examples

### Example 1
Input: moves = "L_RL__R"
Output: 3
Explanation: One optimal sequence is "LLRLLLR" → position = -3


### Example 2

Input: moves = "R__LL"
Output: 5
Explanation: One optimal sequence is "LRLLLLL" → position = -5


## Constraints

- `1 <= n <= 50`
- `moves` consists only of `'L'`, `'R'`, `'_'`

---

## Approach

We count:
- `L` → number of left moves  
- `R` → number of right moves  
- `_` → number of flexible moves (denoted as `U`)  

### Key Insight

Each `'_'` can be used to maximize the distance from the origin.  
So we assign all `'_'` moves in the direction that increases the absolute difference between left and right moves.
