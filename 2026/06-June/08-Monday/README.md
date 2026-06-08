# LeetCode 2161 - Partition Array According to Given Pivot

## Approach
Traverse the array three times:
1. Append elements smaller than pivot.
2. Append elements equal to pivot.
3. Append elements greater than pivot.

This preserves relative ordering within each group.

## Complexity
- Time: O(n)
- Space: O(n)
