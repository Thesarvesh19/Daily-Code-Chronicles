# LeetCode 3090 - Maximum Length Substring With Two Occurrences

## Problem
Given a string `s`, find the length of the longest substring in which every character appears at most twice.

## Approach
Use the **Sliding Window** technique.

- Maintain a window using `left` and `right`.
- Store the frequency of each character.
- Expand the window by moving `right`.
- If any character appears more than twice, move `left` forward until the window becomes valid.
- Keep track of the maximum valid window length.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Example

### Input
```text
bcbbbcba
