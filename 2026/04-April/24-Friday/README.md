# Furthest Point From Origin## ProblemYou are given a string `moves` consisting of characters:- 'L' → move left- 'R' → move right- '_' → can move either left or rightStarting from position `0`, determine the **maximum distance from origin** that can be achieved after performing all moves.---## ApproachWe count:- Number of left moves → `L`- Number of right moves → `R`- Number of flexible moves → `_` (denoted as `U`)### Key InsightFlexible moves (`_`) should always be used to **increase the absolute distance**.So the result is:
abs(R - L) + U
---## Algorithm1. Count occurrences of `'L'`, `'R'`, and `'_'`2. Compute:
distance = abs(R - L) + U
3. Return the result---## Complexity- Time Complexity: `O(n)`- Space Complexity: `O(1)`---## Python Solution```pythonclass Solution: def furthestDistanceFromOrigin(self, moves: str) -> int:     L = moves.count('L')     R = moves.count('R')     U = moves.count('_')          return abs(R - L) + U

Example Walkthrough
Input:
moves = "L_RL__R"
Counts:
L = 2, R = 2, U = 3
Result:
abs(2 - 2) + 3 = 3

