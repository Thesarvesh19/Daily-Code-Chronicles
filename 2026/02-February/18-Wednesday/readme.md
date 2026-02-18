# Binary Number with Alternating Bits

## Problem Statement

Given a positive integer n, determine whether its binary representation has alternating bits.

Two adjacent bits must always have different values.

Example 1:
Input: n = 5
Output: true
Explanation: 5 in binary is 101

Example 2:
Input: n = 7
Output: false
Explanation: 7 in binary is 111

Example 3:
Input: n = 11
Output: false
Explanation: 11 in binary is 1011


## Approach

1. Extract the last bit using (n & 1).
2. Right shift the number using (n >>= 1).
3. Compare the current bit with the next bit.
4. If two adjacent bits are equal, return false.
5. If the loop completes without finding equal adjacent bits, return true.


## Why This Works

By checking one bit at a time and comparing it with the next bit, we ensure that no two adjacent bits are the same.

This avoids integer overflow and undefined behavior.

## Time Complexity

O(log n)

We process each bit once.

## Space Complexity

O(1)

We use only a few integer variables.
