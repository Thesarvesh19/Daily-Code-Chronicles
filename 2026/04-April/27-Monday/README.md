# Check Valid Path in Grid

## Problem
You are given an m x n grid where each cell represents a street type (1 to 6).  
Each type defines allowed movement directions.

Determine if there exists a valid path from the top-left cell (0,0) to the bottom-right cell (m-1,n-1) such that movement follows valid street connections.

## Approach
- Use BFS to traverse the grid.
- Each street allows movement in specific directions.
- Move only if:
  - Current cell allows that direction
  - Next cell connects back

## Complexity
- Time: O(m × n)
- Space: O(m × n)

## Files
- `solution.py` → Python BFS solution
- `solution.java` → Java BFS solution
