# 3783. Mirror Distance of an Integer

class Solution:
    def mirrorDistance(self, n):
        rev = int(str(n)[::-1]) 
        return abs(n - rev)
