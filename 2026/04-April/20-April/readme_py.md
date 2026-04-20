# 2078. Two Furthest Houses With Different Colors (Python)

## Idea
Instead of checking all pairs, observe that the farthest distance must involve either end of the array.

## Strategy
- Fix the first house and scan right to find the farthest different color.
- Fix the last house and scan left to find the farthest different color.
- Take the maximum of both.

## Implementation Detail
Python makes it easy to track the maximum using built-in functions like max(). 

## Complexity
Time: O(n)  
Space: O(1)
