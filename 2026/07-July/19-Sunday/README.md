# LeetCode Notes

# 1081. Smallest Subsequence of Distinct Characters

**Difficulty:** Medium

---

## Problem

Given a string `s`, return the **lexicographically smallest subsequence** that contains **every distinct character exactly once**.

A subsequence is obtained by deleting zero or more characters without changing the relative order of the remaining characters.

---

## Key Observation

The answer must satisfy two conditions:

- Every distinct character appears exactly once.
- The resulting subsequence should be lexicographically smallest.

To achieve this efficiently, use:

- Last occurrence of every character
- Monotonic Stack
- Visited array/set

---

## Why This Works

The greedy strategy always tries to place the smallest possible character as early as possible.

Removing a larger character is safe only when it appears again later in the string.

This guarantees

- uniqueness
- correct order
- minimum lexicographical subsequence

---
