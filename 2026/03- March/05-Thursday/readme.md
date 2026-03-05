# Minimum Operations to Make the Binary String Alternating

## Problem Description
You are given a binary string `s` consisting only of characters `'0'` and `'1'`.  
In one operation, you can change any `'0'` to `'1'` or `'1'` to `'0'`.

A string is considered **alternating** if no two adjacent characters are the same.  
For example:
- `"010"` is alternating
- `"0100"` is **not** alternating

Your task is to return the **minimum number of operations** required to make the string alternating.

## Examples

### Example 1
Input:

s = "0100"

Output:

1

Explanation:  
Changing the last character to `'1'` makes the string `"0101"`, which is alternating.

### Example 2
Input:

s = "10"

Output:

0

Explanation:  
The string is already alternating.

### Example 3
Input:

s = "1111"

Output:

2

Explanation:  
Two operations are required to convert it into `"0101"` or `"1010"`.

## Approach
For a binary string to be alternating, only **two valid patterns** exist:

1. Start with `'0'`: `010101...`
2. Start with `'1'`: `101010...`

We compare the given string against both patterns and count mismatches:
- `count0`: mismatches if the string starts with `'0'`
- `count1`: mismatches if the string starts with `'1'`

The minimum of these two counts gives the **minimum number of operations** needed.

## Algorithm
1. Initialize two counters for mismatches.
2. Traverse the string character by character.
3. Compare each character with the expected value for both alternating patterns.
4. Increment mismatch counters when characters do not match.
5. Return the minimum mismatch count.

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  We traverse the string once.

- **Space Complexity:** `O(1)`  
  Only a few variables are used.

## Implementation (Python)

```python
class Solution:
    def minOperations(self, s: str) -> int:
        start_with_0 = 0
        start_with_1 = 0
        
        for i, ch in enumerate(s):
            if i % 2 == 0:
                if ch != '0':
                    start_with_0 += 1
                if ch != '1':
                    start_with_1 += 1
            else:
                if ch != '1':
                    start_with_0 += 1
                if ch != '0':
                    start_with_1 += 1
        
        return min(start_with_0, start_with_1)
