# Minimum Distance of Good Tuple (Python)

## Problem
Find minimum distance of any tuple (i, j, k) such that:
nums[i] == nums[j] == nums[k]

Distance:
|i - j| + |j - k| + |k - i|

## Key Idea
For i < j < k:
distance = 2 * (k - i)

So we only need first and third index.

## Approach
1. Store indices of each value
2. For each list with size >= 3
3. Check consecutive triples
4. Take minimum

## Complexity
Time: O(n)
Space: O(n)
