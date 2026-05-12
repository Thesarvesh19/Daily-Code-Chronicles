# README.md

# Minimum Initial Energy to Finish Tasks

## Problem
You are given an array `tasks` where each task is represented as:

- `tasks[i][0]` = actual energy required to complete the task
- `tasks[i][1]` = minimum energy required to start the task

Return the minimum initial energy required to finish all tasks.

---

## Approach

1. Sort tasks in descending order of `(minimum - actual)`.
2. This prioritizes tasks that need higher reserve energy.
3. Maintain:
   - `current_energy`
   - `total_energy_needed`
4. If current energy is less than required minimum:
   - Increase initial energy.
5. Deduct actual energy after completing each task.

---

## Python Solution

```python
class Solution:
    def minimumEffort(self, tasks):
        tasks.sort(key=lambda x: (x[1] - x[0]), reverse=True)

        total_energy_needed = 0
        current_energy = 0

        for actual, minimum in tasks:
            if current_energy < minimum:
                total_energy_needed += (minimum - current_energy)
                current_energy = minimum

            current_energy -= actual

        return total_energy_needed
