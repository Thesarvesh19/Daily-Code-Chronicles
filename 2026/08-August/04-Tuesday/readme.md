# LeetCode 3731 – Find Missing Elements

## Problem
Given an integer array `nums`, return all the missing integers that lie strictly between the minimum and maximum values of the array in ascending order.

## Approach
1. Find the minimum and maximum values in the array.
2. Store all elements in a hash set for fast lookup.
3. Iterate from `min + 1` to `max - 1`.
4. Add every number that is not present in the set to the answer.

This approach efficiently finds all missing values while avoiding repeated searches.

## Algorithm
- Determine the smallest and largest elements.
- Insert every array element into a hash set.
- Traverse the range between the minimum and maximum values.
- Collect all numbers that are absent from the set.
- Return the resulting list.

## Complexity Analysis
- **Time Complexity:** `O(n + (max - min))`
- **Space Complexity:** `O(n)`

Where:
- `n` = number of elements in the array.
- `(max - min)` = size of the range being checked.

## Example

**Input**
```text
nums = [1, 4, 7]
```

**Output**
```text
[2, 3, 5, 6]
```

## Key Idea
A hash set provides constant-time membership checks, allowing us to efficiently identify every missing integer between the minimum and maximum values.
