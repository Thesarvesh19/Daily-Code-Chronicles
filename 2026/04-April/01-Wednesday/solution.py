from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        robots = [(positions[i], healths[i], directions[i], i) for i in range(n)]
        
        robots.sort()
        stack = []

        for pos, health, d, idx in robots:
            if d == 'R':
                stack.append([pos, health, d, idx])
            else:
                while stack and stack[-1][2] == 'R':
                    if stack[-1][1] < health:
                        stack.pop()
                        health -= 1
                    elif stack[-1][1] > health:
                        stack[-1][1] -= 1
                        health = 0
                        break
                    else:
                        stack.pop()
                        health = 0
                        break
                if health > 0:
                    stack.append([pos, health, d, idx])

        stack.sort(key=lambda x: x[3])
        return [r[1] for r in stack]
