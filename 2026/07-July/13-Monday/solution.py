from collections import deque

class Solution:
    def hasValidPath(self, grid):
        rows, cols = len(grid), len(grid[0])

        directions = {
            1: [(0, -1), (0, 1)],
            2: [(-1, 0), (1, 0)],
            3: [(0, -1), (1, 0)],
            4: [(0, 1), (1, 0)],
            5: [(0, -1), (-1, 0)],
            6: [(0, 1), (-1, 0)]
        }

        opposite = {
            (0, -1): (0, 1),
            (0, 1): (0, -1),
            (-1, 0): (1, 0),
            (1, 0): (-1, 0)
        }

        seen = [[False] * cols for _ in range(rows)]
        q = deque([(0, 0)])
        seen[0][0] = True

        while q:
            x, y = q.popleft()

            if x == rows - 1 and y == cols - 1:
                return True

            for dx, dy in directions[grid[x][y]]:
                nx, ny = x + dx, y + dy

                if 0 <= nx < rows and 0 <= ny < cols and not seen[nx][ny]:
                    if opposite[(dx, dy)] in directions[grid[nx][ny]]:
                        seen[nx][ny] = True
                        q.append((nx, ny))

        return False
