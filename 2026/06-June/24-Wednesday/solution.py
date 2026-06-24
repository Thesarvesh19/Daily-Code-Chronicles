class Solution:
    MOD = 10**9 + 7

    def multiply(self, A, B):
        n = len(A)
        C = [[0] * n for _ in range(n)]

        for i in range(n):
            for k in range(n):
                if A[i][k] == 0:
                    continue
                for j in range(n):
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % self.MOD

        return C

    def power(self, base, exp):
        n = len(base)
        res = [[0] * n for _ in range(n)]

        for i in range(n):
            res[i][i] = 1

        while exp:
            if exp & 1:
                res = self.multiply(res, base)
            base = self.multiply(base, base)
            exp >>= 1

        return res

    def zigZagArrays(self, n, l, r):
        m = r - l + 1

        U = [[0] * m for _ in range(m)]
        D = [[0] * m for _ in range(m)]

        for i in range(m):
            for j in range(i):
                U[i][j] = 1
            for j in range(i + 1, m):
                D[i][j] = 1

        UD = self.multiply(U, D)

        V = self.power(UD, (n - 1) // 2)

        if (n - 1) % 2:
            V = self.multiply(V, U)

        ans = 0

        for row in V:
            ans = (ans + sum(row)) % self.MOD

        return (ans * 2) % self.MOD
