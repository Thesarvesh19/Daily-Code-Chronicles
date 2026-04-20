# 2078. Two Furthest Houses With Different Colors (C++)

## Insight
Checking all pairs is unnecessary. The answer lies at extremes.

## Algorithm
- Loop through the array once
- Use std::max to track:
  - Distance from first element
  - Distance from last element

## STL Advantage
C++ provides built-in max function to simplify updates.

## Complexity
Time: O(n)  
Space: O(1)
