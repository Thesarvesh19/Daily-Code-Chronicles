class Solution:
    def findRotation(self, mat, target):
        def rotate(matrix):
            n = len(matrix)
            return [[matrix[n - j - 1][i] for j in range(n)] for i in range(n)]

        for _ in range(4):
            if mat == target:
                return True
            mat = rotate(mat)

        return False


# Optional test
if __name__ == "__main__":
    sol = Solution()
    mat = [[0,1],[1,0]]
    target = [[1,0],[0,1]]
    print(sol.findRotation(mat, target))  # True
