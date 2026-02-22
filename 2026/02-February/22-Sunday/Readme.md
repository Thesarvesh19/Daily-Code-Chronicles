# Binary Gap

## Problem Statement

Given a positive integer `n`, return the longest distance between any two adjacent 1's in the binary representation of `n`.

If there are no two adjacent 1's, return 0.

Two 1's are adjacent if there are only 0's separating them (possibly no 0's).

---

## Example

Input:

n = 22


Output:

2


Explanation:
Binary of 22 is `10110`.

Distances between consecutive 1s:
- First pair → distance = 2
- Second pair → distance = 1

Maximum distance = 2

---

## Approach

1. Traverse the binary representation of the number using bitwise operations.
2. Keep track of the last position where a `1` was found.
3. When another `1` is found:
   - Calculate the distance.
   - Update the maximum distance.
4. Return the maximum distance.

---

## Time Complexity

O(log n)  
We process each bit of the number once.

## Space Complexity

O(1)  
