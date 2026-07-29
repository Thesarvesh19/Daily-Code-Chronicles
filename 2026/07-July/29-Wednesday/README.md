# 3518. Smallest Palindromic Rearrangement II

## Problem Statement

You are given a **palindromic** string `s` and an integer `k`.

Return the **k-th lexicographically smallest palindromic permutation** of `s`. If fewer than `k` distinct palindromic permutations exist, return an empty string.

> Different rearrangements that produce the same palindromic string are considered identical and are counted only once.

---

## Approach

Since the input string is already a palindrome:

- Count the frequency of every character.
- Construct only the **left half** of the palindrome using `frequency / 2`.
- Determine the middle character (if one exists).
- Build the left half greedily:
  - Try placing each possible character in lexicographical order.
  - Count how many valid palindromes can be formed with the remaining characters.
  - If that count is smaller than `k`, skip those permutations.
  - Otherwise, fix the character and continue.
- Mirror the left half and append the middle character to obtain the final palindrome.

To avoid unnecessary computation, the number of possible permutations is capped at `10⁶`, which is sufficient because `k ≤ 10⁶`.

---

## Algorithm

1. Count the frequency of each character.
2. Store half of each frequency for palindrome construction.
3. Identify the middle character (if any).
4. Compute the total number of distinct palindromic permutations.
5. If the total number is less than `k`, return an empty string.
6. Construct the left half greedily:
   - Try each available character in lexicographical order.
   - Count the number of remaining valid permutations.
   - Skip or select the character based on the value of `k`.
7. Reverse the left half and append it to complete the palindrome.

---

## Complexity Analysis

- **Time Complexity:** `O(26 × n)`
- **Space Complexity:** `O(26)` ≈ `O(1)`

where `n` is the length of the string.

---

## Example

### Example 1

**Input**

```text
s = "abba", k = 2
```

**Output**

```text
baab
```

### Example 2

**Input**

```text
s = "aa", k = 2
```

**Output**

```text
""
```

### Example 3

**Input**

```text
s = "bacab", k = 1
```

**Output**

```text
abcba
```

---

## Key Concepts

- Greedy Algorithm
- Lexicographical Ordering
- Character Frequency Counting
- Combinatorics
- Binomial Coefficients
- Palindrome Construction
- Mathematical Counting

---

## Summary

This solution efficiently constructs the **k-th lexicographically smallest palindromic rearrangement** without generating every permutation. By combining greedy character selection with combinatorial counting, it handles strings of length up to **10⁴** while remaining within the problem constraints.
