# LeetCode 115 - Distinct Subsequences

## Problem

Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

The answer is guaranteed to fit within a 32-bit signed integer.

### Example

```text
Input:  s = "rabbbit", t = "rabbit"
Output: 3
```

There are three ways to delete characters from `s` to obtain `"rabbit"`.

---

## Approach: Dynamic Programming

Let `dp[j]` represent the number of ways to form the first `j` characters of `t` using the characters processed so far from `s`.

### Initialization

```text
dp[0] = 1
```

There is always exactly one way to form an empty string: choose no characters.

### Transition

For every character in `s`, traverse `t` from right to left.

If:

```text
s[i] == t[j]
```

then:

```text
dp[j + 1] += dp[j]
```

The reverse traversal is important because it prevents the same character from `s` from being used multiple times.

---

## Complexity

* **Time Complexity:** `O(m × n)`
* **Space Complexity:** `O(n)`

Where:

* `m` = length of `s`
* `n` = length of `t`

---

## Supported Languages

* Python
* C++
* C
* C#

## Key Idea

Instead of explicitly generating every subsequence, dynamic programming efficiently counts the number of possible ways to construct the target string.
