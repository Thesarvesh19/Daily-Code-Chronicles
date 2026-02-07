"""
Problem:
Given a string containing only 'a' and 'b', find the minimum number
of deletions required so that all 'a' characters come before any 'b'.

Approach:
- Iterate through the string once.
- Count how many 'b' characters have been seen.
- When an 'a' appears after 'b':
  - Either delete this 'a'
  - Or delete all previous 'b' characters
- Pick the option with fewer deletions.

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution:
    def minimumDeletions(self, s: str) -> int:
        b_count = 0
        deletions = 0

        for ch in s:
            if ch == 'b':
                b_count += 1
            else:  # ch == 'a'
                deletions = min(deletions + 1, b_count)

        return deletions
