var totalWaviness = function(num1, num2) {

    function solve(x) {
        if (x <= 0n) return 0n;

        const s = x.toString();
        const memo = new Map();

        function dfs(pos, prev, prev2, lead, tight) {
            if (pos === s.length) {
                return [1n, 0n];
            }

            const key = `${pos}|${prev}|${prev2}|${lead}`;

            if (!tight && memo.has(key)) {
                return memo.get(key);
            }

            const limit = tight ? Number(s[pos]) : 9;

            let cnt = 0n;
            let wav = 0n;

            for (let d = 0; d <= limit; d++) {

                const ntight = tight && d === limit;
                const nlead = lead && d === 0;

                const [subCnt, subWav] = dfs(
                    pos + 1,
                    nlead ? -1 : d,
                    prev,
                    nlead,
                    ntight
                );

                cnt += subCnt;

                if (
                    !lead &&
                    prev2 !== -1 &&
                    (
                        (prev2 < prev && prev > d) ||
                        (prev2 > prev && prev < d)
                    )
                ) {
                    wav += subCnt;
                }

                wav += subWav;
            }

            const ans = [cnt, wav];

            if (!tight) {
                memo.set(key, ans);
            }

            return ans;
        }

        return dfs(0, -1, -1, true, true)[1];
    }

    return solve(BigInt(num2)) - solve(BigInt(num1) - 1n);
};
