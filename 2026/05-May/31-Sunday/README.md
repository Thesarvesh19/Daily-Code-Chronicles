# 2126. Destroying Asteroids

## Problem Statement

You are given an integer `mass`, representing the mass of a planet, and an integer array `asteroids`, where `asteroids[i]` represents the mass of the `i-th` asteroid.

A planet can destroy an asteroid if its current mass is **greater than or equal to** the asteroid's mass. After destroying the asteroid, the planet gains the asteroid's mass.

Return `true` if it is possible to destroy all asteroids; otherwise, return `false`.

## Approach

To maximize the planet's growth, destroy the smallest asteroids first.

### Steps

1. Sort the asteroid masses in ascending order.
2. Iterate through the sorted array.
3. If the current planet mass is smaller than an asteroid, return `false`.
4. Otherwise, destroy the asteroid and add its mass to the planet.
5. If all asteroids are destroyed, return `true`.

## Algorithm

```text
Sort asteroids

For each asteroid:
    If mass < asteroid:
        Return false
    mass += asteroid

Return true
```

## Python Solution

```python
class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()

        current_mass = mass

        for asteroid in asteroids:
            if current_mass < asteroid:
                return False
            current_mass += asteroid

        return True
```

## Complexity Analysis

### Time Complexity

* Sorting: `O(n log n)`
* Traversal: `O(n)`
* Overall: `O(n log n)`

### Space Complexity

* `O(1)` (excluding sorting space)

## Example

### Input

```text
mass = 10
asteroids = [3,9,19,5,21]
```

### Sorted Asteroids

```text
[3,5,9,19,21]
```

### Simulation

```text
10 -> 13 -> 18 -> 27 -> 46 -> 67
```

### Output

```text
true
```

## Key Insight

Destroying smaller asteroids first allows the planet to grow as quickly as possible, ensuring the highest chance of absorbing larger asteroids later.
