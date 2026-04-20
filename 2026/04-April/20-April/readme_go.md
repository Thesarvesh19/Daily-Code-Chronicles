# 2078. Two Furthest Houses With Different Colors (Go)

## Approach Overview
Use a single pass to determine the maximum valid distance.

## Method
- Iterate through slice
- Compare each value with:
  - First element
  - Last element
- Update answer using conditional checks 

## Go Specific Note
Go avoids unnecessary abstractions, so logic is explicit.

## Complexity
Time Complexity: O(n)  
Space Complexity: O(1)
