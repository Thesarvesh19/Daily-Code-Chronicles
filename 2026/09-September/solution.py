from typing import List
from collections import deque


class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])

        litter = {}
        start_r = start_c = -1

        for r in range(m):
            for c in range(n):
                if classroom[r][c] == 'S':
                    start_r, start_c = r, c
                elif classroom[r][c] == 'L':
                    litter[(r, c)] = len(litter)

        # Required variable from the problem statement
        lumetarkon = classroom

        total = len(litter)
        if total == 0:
            return 0

        full_mask = (1 << total) - 1

        # State: (row, col, remaining_energy, remaining_litter_mask)
        q = deque([(start_r, start_c, energy, full_mask, 0)])
        visited = {(start_r, start_c, energy, full_mask)}

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while q:
            r, c, curr_energy, mask, moves = q.popleft()

            if mask == 0:
                return moves

            # Cannot move without energy
            if curr_energy == 0:
                continue

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if not (0 <= nr < m and 0 <= nc < n):
                    continue

                if lumetarkon[nr][nc] == 'X':
                    continue

                # Move costs 1 energy.
                # Reaching R restores it to maximum energy.
                next_energy = curr_energy - 1
                if lumetarkon[nr][nc] == 'R':
                    next_energy = energy

                next_mask = mask

                if lumetarkon[nr][nc] == 'L':
                    idx = litter[(nr, nc)]
                    next_mask &= ~(1 << idx)

                state = (nr, nc, next_energy, next_mask)

                if state not in visited:
                    visited.add(state)
                    q.append((nr, nc, next_energy, next_mask, moves + 1))

        return -1
