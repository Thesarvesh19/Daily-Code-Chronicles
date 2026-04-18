# 3783. Mirror Distance of an Integer

## Approach
- Reverse the digits of the integer.
- Compute absolute difference between original and reversed number.

## Logic
- Convert to string and reverse OR use math. 
- Return abs(n - reversed_n)

## Complexity
- Time: O(d), where d = number of digits
- Space: O(1) (math) / O(d) (string)

## Example
Input: n = 25
Output: 27

Explanation:
reverse(25) = 52
abs(25 - 52) = 27
