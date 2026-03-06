# Single Contiguous Ones Segment Check (Java)

## Problem Statement
Given a binary string `s` starting with `1`, determine whether it contains **only one continuous block of `1`s**.

If `1`s appear again after a `0`, the string contains multiple segments and the answer should be `false`.

## Examples

Example 1

Input:

s = "1001"


Output:

false


Example 2

Input:

s = "110"


Output:

true


## Algorithm

The solution scans the string once while maintaining a boolean flag.

Algorithm steps:

1. Initialize a boolean variable indicating whether a `0` has been encountered.
2. Iterate through each character in the string.
3. If a `0` is found, update the flag.
4. If a `1` appears after the flag is set, return `false`.
5. If the scan completes without violation, return `true`.

## Performance

Time Complexity: `O(n)` where `n` is the length of the string.

Space Complexity: `O(1)` since no extra data structures are used.
