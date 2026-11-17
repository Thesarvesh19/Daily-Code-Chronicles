# 2911. Minimum Changes to Make K Semi-palindromes

## Problem Statement
Given a string `s` and an integer `k`, divide the string into exactly `k` non-overlapping contiguous substrings, each having a length of at least 2.

A string is called a **semi-palindrome** if there exists a proper divisor `d` of its length such that characters at positions with the same remainder modulo `d` form palindromes.

Return the minimum number of character changes required to make all `k` substrings semi-palindromes.

## Approach: Dynamic Programming + Precomputation

### 1. Precompute Substring Costs
- Consider every possible substring of length at least 2.
- Enumerate all proper divisors of its length.
- For each divisor, compare corresponding characters in the resulting sequences.
- Count the mismatched character pairs.
- Store the minimum number of changes required in a cost matrix.

### 2. Dynamic Programming
Define:

`dp[i][parts]` = minimum changes required to divide the suffix starting at index `i` into exactly `parts` semi-palindromic substrings.

**Base Case:**

`dp[n][0] = 0`

All other states are initially set to infinity.

**Transition:**

Try every valid ending position `j` and calculate:

`dp[i][parts] = min(dp[i][parts], cost[i][j] + dp[j+1][parts-1])`

The final answer is `dp[0][k]`.

## Complexity Analysis

Let `n` be the length of the string.

- **Time Complexity:** `O(n³ log n + n²k)`
- **Space Complexity:** `O(n² + nk)`

## Languages Implemented
- Python
- Java
- C
- C++
- C#

## Key Concepts
- Dynamic Programming
- String Manipulation
- Divisors
- Palindrome Checking
- Precomputation

## Learning Outcome
This problem demonstrates how preprocessing substring costs and combining them with dynamic programming can efficiently solve string partitioning problems involving multiple constraints.
