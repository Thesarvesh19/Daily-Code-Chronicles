LeetCode 2267: Check if There Is a Valid Parentheses String Path

This repository contains solutions for LeetCode 2267 in Python, Java, and C++.

Problem Overview

Given an $m \times n$ grid consisting of characters '(' and ')', find whether there is a valid parentheses string path from the top-left corner (0, 0) to the bottom-right corner (m - 1, n - 1).

A path is valid if:

It starts at (0, 0) and ends at (m - 1, n - 1).

At each step, you can only move either down or right.

The resulting string concatenation forms a valid parentheses string.

Approach & Intuition

The problem can be solved using Depth-First Search (DFS) with Memoization (Dynamic Programming):

Quick Validations:

The total path length is $m + n - 1$. If this length is odd, it's impossible to balance parentheses, so return false.

The path must start with '(' and end with ')'.

State Tracking (i, j, k):

i, j: Current coordinates in the grid.

k: Current balance of opening brackets (+1 for '(', -1 for ')').

Pruning:

If balance $k < 0$, we have encountered more closing brackets than opening ones (invalid path).

If $k$ exceeds the remaining steps to the destination, we won't have enough characters to close them.

Memoization:

We cache the results of states (i, j, k) to avoid redundant subproblem evaluations, ensuring optimal performance.

Solutions Included

Python 3 (@cache based DFS)

Java (3D Boolean array memoization)

C++ (3D vector memoization)

Complexity Analysis

Time Complexity: $\mathcal{O}(m \cdot n \cdot (m + n))$

There are $m \times n$ cells, and the balance value $k$ is bounded by $m + n$. Each unique state is visited at most once.

Space Complexity: $\mathcal{O}(m \cdot n \cdot (m + n))$

Required for storing memoization tables and the recursion stack depth.
