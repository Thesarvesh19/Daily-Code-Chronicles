class Solution {
    constructor() {
        this.MOD = 1000000007n;
    }

    multiply(A, B) {
        const n = A.length;
        const C = Array.from({ length: n }, () =>
            Array(n).fill(0n)
        );

        for (let i = 0; i < n; i++) {
            for (let k = 0; k < n; k++) {
                if (A[i][k] === 0n) continue;

                for (let j = 0; j < n; j++) {
                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % this.MOD;
                }
            }
        }

        return C;
    }

    power(base, exp) {
        const n = base.length;

        let res = Array.from({ length: n }, (_, i) =>
            Array.from({ length: n }, (_, j) =>
                i === j ? 1n : 0n
            )
        );

        while (exp > 0) {
            if (exp & 1) {
                res = this.multiply(res, base);
            }

            base = this.multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    zigZagArrays(n, l, r) {
        const m = r - l + 1;

        const U = Array.from({ length: m }, () =>
            Array(m).fill(0n)
        );

        const D = Array.from({ length: m }, () =>
            Array(m).fill(0n)
        );

        for (let i = 0; i < m; i++) {
            for (let j = 0; j < i; j++) {
                U[i][j] = 1n;
            }

            for (let j = i + 1; j < m; j++) {
                D[i][j] = 1n;
            }
        }

        const UD = this.multiply(U, D);

        let V = this.power(UD, Math.floor((n - 1) / 2));

        if ((n - 1) % 2) {
            V = this.multiply(V, U);
        }

        let ans = 0n;

        for (const row of V) {
            for (const val of row) {
                ans = (ans + val) % this.MOD;
            }
        }

        return Number((ans * 2n) % this.MOD);
    }
}
