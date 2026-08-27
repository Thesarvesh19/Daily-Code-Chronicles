# 3720. Lexicographically Smallest Permutation Greater Than Target

## Problem

You are given two strings `s` and `target`, both of length `n`, consisting of lowercase English letters.

Return the **lexicographically smallest permutation of `s`** that is **strictly greater than `target`**.

If no permutation of `s` is lexicographically greater than `target`, return an empty string `""`.

A string `a` is lexicographically greater than a string `b` if, at the first position where they differ, `a` contains a character that appears later in the alphabet than the corresponding character in `b`.

---

## Examples

### Example 1

**Input:**

```text
s = "abc"
target = "bba"
