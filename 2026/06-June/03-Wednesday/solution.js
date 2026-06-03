var earliestFinishTime = function(
    landStartTime,
    landDuration,
    waterStartTime,
    waterDuration
) {

    const solve = (s1, d1, s2, d2) => {

        let rides = [];

        for (let i = 0; i < s2.length; i++)
            rides.push([s2[i], d2[i]]);

        rides.sort((a, b) => a[0] - b[0]);

        const m = rides.length;

        const start = Array(m);
        const pref = Array(m);
        const suf = Array(m);

        for (let i = 0; i < m; i++)
            start[i] = rides[i][0];

        pref[0] = rides[0][1];

        for (let i = 1; i < m; i++)
            pref[i] = Math.min(pref[i - 1], rides[i][1]);

        suf[m - 1] = rides[m - 1][0] + rides[m - 1][1];

        for (let i = m - 2; i >= 0; i--)
            suf[i] = Math.min(
                suf[i + 1],
                rides[i][0] + rides[i][1]
            );

        let ans = Number.MAX_SAFE_INTEGER;

        for (let i = 0; i < s1.length; i++) {

            let finish = s1[i] + d1[i];

            let l = 0, r = m;

            while (l < r) {
                let mid = (l + r) >> 1;
                if (start[mid] < finish)
                    l = mid + 1;
                else
                    r = mid;
            }

            let pos = l;

            if (pos > 0)
                ans = Math.min(
                    ans,
                    finish + pref[pos - 1]
                );

            if (pos < m)
                ans = Math.min(
                    ans,
                    suf[pos]
                );
        }

        return ans;
    };

    return Math.min(
        solve(landStartTime, landDuration,
              waterStartTime, waterDuration),
        solve(waterStartTime, waterDuration,
              landStartTime, landDuration)
    );
};
