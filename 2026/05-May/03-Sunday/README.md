# LeetCode 796 — Rotate String

## 🧠 Problem Summary

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of rotations.

A rotation moves the leftmost character of the string to the rightmost position.

---

## 💡 Approach

The key observation is:

* If `goal` is a rotation of `s`, then it must be a substring of `s + s`.
* Also, both strings must have equal length.

So we:

1. Check if lengths are equal
2. Check if `goal` exists inside `s + s`

---

## 🧾 Python Solution

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and goal in s + s
```

---

## ⏱ Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

---

## 🚀 Commit Message

```
Add Python solution for LeetCode 796 using string concatenation trick
```
