class Solution:
    def minOperations(self, s: str) -> int:
        start_with_0 = 0
        start_with_1 = 0
        
        for i, ch in enumerate(s):
            if i % 2 == 0:
                if ch != '0':
                    start_with_0 += 1
                if ch != '1':
                    start_with_1 += 1
            else:
                if ch != '1':
                    start_with_0 += 1
                if ch != '0':
                    start_with_1 += 1
        
        return min(start_with_0, start_with_1)
