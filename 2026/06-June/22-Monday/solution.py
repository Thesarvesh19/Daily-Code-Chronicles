class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        # Har required character ki frequency count karo
        b_count = text.count('b')
        a_count = text.count('a')
        l_count = text.count('l') // 2  # Divided by 2 because we need two 'l's
        o_count = text.count('o') // 2  # Divided by 2 because we need two 'o's 
        n_count = text.count('n')
        
        # Jo sabse minimum hoga, utne hi complete words ban payenge
        return min(b_count, a_count, l_count, o_count, n_count)
