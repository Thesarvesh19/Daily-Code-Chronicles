# LeetCode 3360 - Stone Removal Game

- **Problem Number:** 3360
- **Platform:** LeetCode
- **Difficulty:** Easy
- **Language:** Python 3
- **Topics:** Simulation, Game Theory

## Approach

The problem is solved using simulation. Alice starts by removing 10 stones, and the number of stones required decreases by 1 after every turn.

Players alternate turns. The player who cannot remove the required number of stones loses the game.

## Python Solution

class Solution:
    def canAliceWin(self, n: int) -> bool:
        turn = 10

        while n >= turn:
            n -= turn
            turn -= 1

        return turn != 10

## Complexity Analysis

- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

## Example

**Input:**
n = 12

**Output:**
True

**Explanation:**
- Alice removes 10 stones.
- Remaining stones = 2.
- Bob cannot remove 9 stones.
- Therefore, Alice wins.

## Key Concepts

- Simulation
- Game Theory
- Greedy Logic

## Learning Outcome

Learned how to implement turn-based game logic using simple simulation and conditional statements.
