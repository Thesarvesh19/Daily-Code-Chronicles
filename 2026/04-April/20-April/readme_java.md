# 2078. Two Furthest Houses With Different Colors (Java)

## Key Observation
The maximum distance is always between two houses that are as far apart as possible.

## Steps
1. Start from index 0 and find the farthest index where color differs.
2. Start from index n-1 and find the farthest index where color differs.
3. Compare both distances.
 
## Why This Works
Any optimal pair must include at least one boundary.

## Complexity Analysis
Time Complexity: O(n)  
Space Complexity: O(1)
