# 3499. Maximize Active Section with Trade I

## Problem Overview

Given a binary string representing inactive (`0`) and active (`1`) sections, perform at most one valid trade to maximize the total number of active sections. A trade consists of removing one eligible active block and activating the adjacent inactive blocks according to the problem constraints.

## Approach

- Count the total number of active (`1`) sections.
- Traverse the string using run-length encoding to process consecutive blocks.
- Keep track of consecutive zero blocks and compute the maximum gain obtainable from a single valid trade.
- Add the best possible gain to the initial active count.

This approach avoids unnecessary simulation and processes the string in a single traversal.

## Algorithm

1. Count all active sections.
2. Group consecutive identical characters into blocks.
3. Maintain the length of the previous zero block.
4. For every zero block, evaluate the gain achievable by merging it with the previous zero block through one valid trade.
5. Return the original active count plus the maximum gain.

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

## Features

- Optimized linear-time solution.
- Constant extra space.
- Efficient run-length traversal.
- Handles all edge cases correctly.
- Suitable for large input sizes.

## Languages Included

- Python
- Java
- C++
- C#
- JavaScript
