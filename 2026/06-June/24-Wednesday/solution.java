class Solution {
    static final long MOD = 1_000_000_007L;

    private long[][] multiply(long[][] A, long[][] B) {
        int n = A.length;
        long[][] C = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    private long[][] power(long[][] base, long exp) {
        int n = base.length;
        long[][] res = new long[n][n];

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    public int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        long[][] U = new long[m][m];
        long[][] D = new long[m][m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                U[i][j] = 1;
            }
            for (int j = i + 1; j < m; j++) {
                D[i][j] = 1;
            }
        }

        long[][] UD = multiply(U, D);
        long[][] V = power(UD, (n - 1) / 2);

        if ((n - 1) % 2 == 1) {
            V = multiply(V, U);
        }

        long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + V[i][j]) % MOD;
            }
        }

        return (int)((ans * 2) % MOD);
    }
}
