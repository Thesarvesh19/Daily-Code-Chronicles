# LeetCode 3505 – Minimum Operations to Make Elements Within K Subarrays Equal

## Problem
Given an integer array `nums`, and two integers `x` and `k`, select exactly `k` non-overlapping subarrays of length `x`.

For each selected subarray, the goal is to make all its elements equal using the minimum number of operations. One operation increments or decrements an element by 1.

Return the minimum total number of operations required.

## Approach: Sliding Window + Two Heaps + Dynamic Programming

### 1. Sliding Window with Two Heaps
- Maintain two heaps to efficiently calculate the median of each window of size `x`.
- The max heap (`small`) stores the smaller half of the elements.
- The min heap (`large`) stores the larger half.
- Use lazy deletion to efficiently remove elements from the sliding window.

### 2. Calculate Window Cost
Making every element equal to the median minimizes the total number of operations.

The cost is calculated as:

`median * smallSize - smallSum + largeSum - median * largeSize`

Store the minimum operation cost for every window of length `x`.

### 3. Dynamic Programming
Define:

`dp[j][i]` = Minimum cost of selecting exactly `j` non-overlapping subarrays within the first `i` elements.

For each position, either:
- Skip the current element.
- Select a subarray of length `x` ending at the current position.

Transition:

`dp[j][i] = min(dp[j][i-1], dp[j-1][i-x] + cost[i-x])`

Space optimization is achieved using two DP arrays.

## Complexity Analysis

| Complexity | Value |
|---|---|
| Time | O(n log x + n × k) |
| Space | O(n + x) |

Where:
- `n` = Number of elements in the array.
- `x` = Length of each selected subarray.
- `k` = Number of non-overlapping subarrays to select.

## Concepts Used
- Sliding Window
- Priority Queue (Max Heap and Min Heap)
- Lazy Deletion
- Median Calculation
- Dynamic Programming
- Space Optimization

## Languages
- Python 3
- Java

## Key Learning
Using two heaps allows efficient median maintenance in a sliding window, while dynamic programming helps select exactly `k` non-overlapping subarrays with the minimum total operation cost.

---

