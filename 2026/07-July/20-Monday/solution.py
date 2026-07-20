class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])
        total = rows * cols

        k %= total
        shifted = [[0] * cols for _ in range(rows)]

        for r in range(rows):
            for c in range(cols):
                current = r * cols + c
                target = (current + k) % total

                nr = target // cols
                nc = target % cols

                shifted[nr][nc] = grid[r][c]

        return shifted
