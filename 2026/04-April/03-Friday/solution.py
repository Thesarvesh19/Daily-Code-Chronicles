from typing import List
from bisect import bisect_left
from functools import lru_cache

class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        n = len(robots)

        robot_distance_pairs = sorted(zip(robots, distance))
        walls.sort()

        @lru_cache(None)
        def dp(robot_idx: int, next_robot_moved_right: int) -> int:
            if robot_idx < 0:
                return 0

            current_pos, current_distance = robot_distance_pairs[robot_idx]

            # Move Left
            left_boundary = current_pos - current_distance
            if robot_idx > 0:
                prev_pos = robot_distance_pairs[robot_idx - 1][0]
                left_boundary = max(left_boundary, prev_pos + 1)

            l = bisect_left(walls, left_boundary)
            r = bisect_left(walls, current_pos + 1)
            walls_left = r - l

            res_left = dp(robot_idx - 1, 0) + walls_left

            # Move Right
            right_boundary = current_pos + current_distance
            if robot_idx + 1 < n:
                next_pos, next_dist = robot_distance_pairs[robot_idx + 1]
                if next_robot_moved_right == 0:
                    right_boundary = min(right_boundary, next_pos - next_dist - 1)
                else:
                    right_boundary = min(right_boundary, next_pos - 1)

            if right_boundary < current_pos:
                walls_right = 0
            else:
                l = bisect_left(walls, current_pos)
                r = bisect_left(walls, right_boundary + 1)
                walls_right = r - l

            res_right = dp(robot_idx - 1, 1) + walls_right

            return max(res_left, res_right)

        return dp(n - 1, 1)
