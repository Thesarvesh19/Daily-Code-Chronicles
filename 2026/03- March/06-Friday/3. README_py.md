# Check if Binary String Has at Most One Segment of Ones (Python)

## Problem
Given a binary string `s` without leading zeros, determine whether the string contains **at most one contiguous segment of ones**.

A contiguous segment means that all `1`s appear together without being separated by `0`s.

## Example

Input:

s = "1001"


Output:

false


Explanation: The ones are separated by zeros, forming more than one segment.

Input:

s = "110"


Output:

true


Explanation: All ones appear together.

## Approach

We traverse the string and track whether a `0` has already appeared after the initial sequence of `1`s.

Steps:
1. Iterate through each character.
2. When a `0` is encountered, mark that a zero has been seen.
3. If a `1` appears after a zero, then there are multiple segments of ones.
4. Return `false` in that case.
5. Otherwise return `true`.

## Complexity

Time Complexity: `O(n)`  
Space Complexity: `O(1)`
