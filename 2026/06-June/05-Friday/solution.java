class Solution {
    private String num;
    private Long[][][][][] memoCnt;
    private Long[][][][][] memoWav;

    private long[] dfs(int pos, int prev, int prev2,
                       int lead, int tight) {

        if (pos == num.length()) {
            return new long[]{1, 0};
        }

        if (tight == 0 &&
            memoCnt[pos][prev + 1][prev2 + 1][lead][0] != null) {

            return new long[]{
                memoCnt[pos][prev + 1][prev2 + 1][lead][0],
                memoWav[pos][prev + 1][prev2 + 1][lead][0]
            };
        }

        int limit = tight == 1 ? num.charAt(pos) - '0' : 9;

        long cnt = 0;
        long wav = 0;

        for (int d = 0; d <= limit; d++) {

            int ntight = (tight == 1 && d == limit) ? 1 : 0;
            int nlead = (lead == 1 && d == 0) ? 1 : 0;

            int nprev2 = prev;
            int nprev = nlead == 1 ? -1 : d;

            long[] res =
                dfs(pos + 1, nprev, nprev2, nlead, ntight);

            long subCnt = res[0];
            long subWav = res[1];

            cnt += subCnt;

            if (lead == 0 &&
                prev2 != -1 &&
                ((prev2 < prev && prev > d) ||
                 (prev2 > prev && prev < d))) {

                wav += subCnt;
            }

            wav += subWav;
        }

        if (tight == 0) {
            memoCnt[pos][prev + 1][prev2 + 1][lead][0] = cnt;
            memoWav[pos][prev + 1][prev2 + 1][lead][0] = wav;
        }

        return new long[]{cnt, wav};
    }

    private long solve(long x) {

        if (x <= 0) return 0;

        num = String.valueOf(x);

        int n = num.length();

        memoCnt = new Long[n][11][11][2][1];
        memoWav = new Long[n][11][11][2][1];

        return dfs(0, -1, -1, 1, 1)[1];
    }

    public long totalWaviness(long num1, long num2) {
        return solve(num2) - solve(num1 - 1);
    }
}
