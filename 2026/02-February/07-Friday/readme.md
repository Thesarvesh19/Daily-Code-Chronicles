# Minimum Deletions to Balance a and b

## Problem Description
You are given a string that contains only the characters 'a' and 'b'.
Your task is to determine the minimum number of deletions required so
that all 'a' characters appear before any 'b' characters.

The resulting string should follow this pattern:
aaa...bbb...

## Example
Input:
baabb

Output:
2

Explanation:
By deleting two characters, the string can be transformed into "aabb".

## Approach
The idea is to scan the string from left to right:

- Keep track of how many 'b' characters have already appeared.
- When an 'a' is encountered after a 'b', this breaks the required order.
- At this point, choose the cheaper option:
  - Delete the current 'a'
  - Or delete all previous 'b' characters

The minimum of these choices gives the optimal result.

## Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(1)

## Available Solutions
- Java implementation
- Python implementation
