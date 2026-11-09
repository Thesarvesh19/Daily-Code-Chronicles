# LeetCode 1606 - Find Servers That Handled Most Number of Requests

## Problem Description

You are given `k` servers numbered from `0` to `k - 1` and two arrays, `arrival` and `load`.

- `arrival[i]` represents the arrival time of the `i-th` request.
- `load[i]` represents the time required to process the `i-th` request.

Each request is assigned to the first available server whose index is greater than or equal to `i % k`. If no such server exists, the search wraps around to the smallest available server.

If all servers are busy, the request is dropped.

Return the list of servers that handled the maximum number of requests.

## Approach

The solution uses two main data structures:

1. **TreeSet / Sorted Available Servers:** Maintains available server indices in sorted order and efficiently finds the next available server.
2. **Min Heap / Priority Queue:** Tracks busy servers according to their request completion times.

### Algorithm

1. Initialize all servers as available.
2. Process requests in their arrival order.
3. Release all servers whose processing time has finished.
4. If no server is available, skip the request.
5. Find the smallest available server greater than or equal to `i % k`.
6. If no such server exists, select the smallest available server.
7. Assign the request and update the server's request count.
8. Find the maximum request count.
9. Return all servers having that maximum count.

## Complexity Analysis

Let:
- `n` = Number of requests.
- `k` = Number of servers.

For the Java implementation:

- **Time Complexity:** O((n + k) log k)
- **Space Complexity:** O(n + k)

For the C implementation using an array-based sorted list:

- **Time Complexity:** O(nk + n log n)
- **Space Complexity:** O(n + k)

## Key Concepts

- Min Heap
- Priority Queue
- Binary Search
- Sorted Data Structures
- Greedy Algorithm
- Server Scheduling

## Languages Implemented

- [x] Python
- [x] Java
- [x] C

## LeetCode

**Problem Number:** 1606

**Problem Name:** Find Servers That Handled Most Number of Requests

**Difficulty:** Hard

**Platform:** [LeetCode](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)
