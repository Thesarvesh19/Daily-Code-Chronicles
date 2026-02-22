class Solution:
    def binaryGap(self, n):
        last_position = -1
        max_distance = 0
        position = 0
        
        while n > 0:
            if n & 1:
                if last_position != -1:
                    max_distance = max(max_distance, position - last_position)
                last_position = position
            
            n >>= 1
            position += 1
        
        return max_distance


if __name__ == "__main__":
    n = int(input("Enter a number: "))
    sol = Solution()
    print("Longest Binary Gap:", sol.binaryGap(n))
