class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # Track the most recent index of each character
        last_seen = {'a': -1, 'b': -1, 'c': -1}
        total_count = 0
        
        for i, char in enumerate(s):
            last_seen[char] = i
            # If all characters have been seen, min() will be >= 0
            total_count += min(last_seen.values()) + 1
            
        return total_count
