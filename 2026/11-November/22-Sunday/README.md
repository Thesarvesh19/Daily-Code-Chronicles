
# LeetCode 2124 – Check if All A's Appears Before All B's

## Problem Statement

Given a string `s` consisting of only the characters `'a'` and `'b'`, return `true` if all `'a'` characters appear before all `'b'` characters in the string. Otherwise, return `false`.

## Python Solution

```python
class Solution:
    def checkString(self, s: str) -> bool:
        return "ba" not in s
```

## Explanation

- All `'a'` characters must appear before all `'b'` characters.
- If the substring `"ba"` appears, an `'a'` occurs after a `'b'`, violating the condition.
- If `"ba"` is not present, the string satisfies the condition, so we return `True`.

## Example 1

**Input:**
`s = "aaabbb"`

**Output:**
`true`

**Explanation:** All `'a'` characters appear before all `'b'` characters.

## Example 2

**Input:**
`s = "abab"`

**Output:**
`false`

**Explanation:** The substring `"ba"` occurs in the string, meaning an `'a'` appears after a `'b'`.

## Complexity Analysis

- **Time Complexity:** O(n) — Searching for the substring `"ba"` takes linear time in the worst case.
- **Space Complexity:** O(1) — No additional data structures are required.

## Key Takeaway

Checking whether `"ba"` exists in the string is sufficient to determine if all `'a'` characters appear before all `'b'` characters.

---

### Commit Message

`Add Python solution for LeetCode 2124`
