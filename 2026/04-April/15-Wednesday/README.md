# 2515. Shortest Distance to Target String in a Circular Array

## Problem Statement

You are given a 0-indexed circular string array `words` and a string `target`.

A circular array means:
- Next index: (i + 1) % n
- Previous index: (i - 1 + n) % n

Starting from `startIndex`, you can move left or right.

Return the shortest distance to reach `target`.
If target does not exist, return -1.

## Approach

- Traverse all indices.
- For each occurrence of target:
  - Compute circular distance:
    min(|i - startIndex|, n - |i - startIndex|)
- Return minimum distance.
- If not found, return -1.

## Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

## Languages Implemented

- Python
- Java
- Kotlin
- C++
- C
- JavaScript
- C#
- Go

## Key Insight

Circular distance is minimized by choosing:
min(direct distance, wrap-around distance)
