# Minimum Moves to Collect All Litter

## Approach

We need to collect all cells containing `L` while moving through the classroom.

The classroom contains:

- `S` - Starting position
- `L` - Litter that must be collected
- `R` - Recharge station that restores energy to the maximum value
- `X` - Obstacle that cannot be crossed

Each movement to an adjacent cell costs `1` unit of energy.

The goal is to collect all litter using the minimum number of moves.

## Algorithm

We use **Breadth-First Search (BFS)**.

Each BFS state contains:

- Current row
- Current column
- Remaining energy
- Bitmask representing the litter that is still not collected

The state is represented as:

```text
(row, column, remainingEnergy, remainingLitterMask)
