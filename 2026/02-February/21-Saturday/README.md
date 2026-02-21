# Count Numbers with Prime Set Bits

## Problem Statement

Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

A set bit means a bit with value 1 in the binary representation of a number.

Example:
Input: left = 6, right = 10
Output: 4

## Approach

1. Iterate through all numbers from left to right.
2. For each number:
   - Count the number of set bits using Java's built-in Integer.bitCount() method.
   - Check if the count of set bits is a prime number.
3. If it is prime, increase the result counter.
4. Return the final count.

Since the maximum number is 10^6, the maximum possible set bits is around 20, so prime checking is efficient.

## Time Complexity

O(N)

Where N = right - left

- We iterate once through the range.
- Prime checking runs in constant time since the number of set bits is small.

## Space Complexity

O(1)

No extra data structures are used.


You may add a main method for testing if required.
