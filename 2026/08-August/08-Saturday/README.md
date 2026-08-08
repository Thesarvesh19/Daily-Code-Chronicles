# LeetCode 3302 — Find the Lexicographically Smallest Valid Sequence

## Approach

Use a **greedy + suffix matching** approach.

1. Traverse `word1` from right to left to find the rightmost valid positions for matching the suffix of `word2`.
2. Traverse `word1` from left to right.
3. Always choose an exact match when possible.
4. If characters differ, use the **one allowed mismatch** only when the remaining part of `word2` can still be matched exactly.
5. The first valid sequence found is lexicographically smallest.

## Complexity

- **Time:** `O(n + m)`
- **Space:** `O(m)`

Where:
- `n = word1.length`
- `m = word2.length`

## Example

```text
Input:
word1 = "bacdc"
word2 = "abc"

Output:
[1, 2, 4]
