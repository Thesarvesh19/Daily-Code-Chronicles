
# 3619. Count Islands With Total Value Divisible by K

## Problem Description
Given an `m x n` grid and an integer `k`, count the islands whose total cell value is divisible by `k`.

An island consists of connected cells with positive values, connected horizontally or vertically. Cells with value `0` represent water.

An island is valid if the sum of all its cell values is divisible by `k`.

## Approach: Depth-First Search (DFS)

1. Traverse every cell in the grid.
2. If a cell has a positive value, start an iterative DFS using a stack.
3. Calculate the sum of all positive cells connected to that cell.
4. Mark visited cells as `0` to avoid visiting them again.
5. If the island sum is divisible by `k`, increment the answer.
6. Return the total count.

## C++ Solution

```cpp
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                stack<pair<int, int>> st;
                st.push({i, j});

                long long total = grid[i][j];
                grid[i][j] = 0;

                while (!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < m &&
                            ny >= 0 && ny < n &&
                            grid[nx][ny] > 0) {

                            total += grid[nx][ny];
                            grid[nx][ny] = 0;
                            st.push({nx, ny});
                        }
                    }
                }

                if (total % k == 0)
                    count++;
            }
        }

        return count;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(m * n)` — Each cell is visited at most once.
- **Space Complexity:** `O(m * n)` — The DFS stack can contain up to all grid cells.

## Key Concepts
- Depth-First Search (DFS)
- Graph Traversal
- Connected Components
- Matrix Traversal
- Stack

## Tags
`Array` `Matrix` `Depth-First Search` `Graph` `Connected Components`
