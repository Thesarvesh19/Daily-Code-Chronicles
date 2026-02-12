"""
3713. Longest Balanced Substring I

You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring
appear the same number of times.

Return the length of the longest balanced substring of s.

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
"""

class Solution:
    def longestBalanced(self, s):
        n = len(s)
        ans = 0
        
        for i in range(n):
            freq = [0] * 26
            distinct = 0
            maxFreq = 0
            
            for j in range(i, n):
                idx = ord(s[j]) - ord('a')
                
                if freq[idx] == 0:
                    distinct += 1
                    
                freq[idx] += 1
                maxFreq = max(maxFreq, freq[idx])
                
                length = j - i + 1
                
                # Balanced condition
                if length == distinct * maxFreq:
                    ans = max(ans, length)
        
        return ans
