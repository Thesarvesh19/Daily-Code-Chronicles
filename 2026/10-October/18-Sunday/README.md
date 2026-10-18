# 1569. Number of Ways to Reorder Array to Get Same BST

## Problem Statement
Given an array of distinct integers `nums`, find the number of ways to reorder the array so that it produces the same Binary Search Tree (BST) as the original array.

Return the answer modulo `10^9 + 7`.

The original ordering should not be counted in the answer.

## Approach: Recursion and Combinatorics

1. Consider the first element as the root of the BST.
2. Divide the remaining elements into two groups:
   - **Left subtree:** Elements smaller than the root.
   - **Right subtree:** Elements greater than the root.
3. Recursively calculate the number of valid reorderings for both subtrees.
4. Use combinations to calculate the number of ways to interleave the left and right subtree elements while preserving their relative order.
5. Multiply the results for both subtrees and the combination count.
6. Subtract `1` to exclude the original ordering.

## Complexity Analysis

- **Time Complexity:** `O(n^2)`
- **Space Complexity:** `O(n^2)`

Here, `n` is the length of the input array.

## Languages
- Python
- C++
- Java

## Example

**Input:**
```text
nums = [2, 1, 3]
```

**Output:**
```text
1
```

**Explanation:**

The original array creates a BST with root `2`, left child `1`, and right child `3`.

The ordering `[2, 3, 1]` creates the same BST. Excluding the original ordering, exactly one valid reordering remains.

## Key Takeaway
The problem combines recursive BST construction with binomial coefficients to count valid reorderings efficiently.
