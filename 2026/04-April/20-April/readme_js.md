# 2078. Two Furthest Houses With Different Colors (JavaScript)

## Thought Process
The widest gap comes from comparing endpoints with other elements.

## Execution Plan
- Iterate over array
- For each index:
  - Check difference with first color
  - Check difference with last color
- Update result using Math.max

## Language Feature
JavaScript's dynamic typing and Math utilities simplify logic.

## Complexity
Time Complexity: O(n)  
Space Complexity: O(1)
