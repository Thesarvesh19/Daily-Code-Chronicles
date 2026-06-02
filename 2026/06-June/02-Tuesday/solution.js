var earliestFinishTime = function (
    landStartTime,
    landDuration,
    waterStartTime,
    waterDuration
) {
    const calc = (firstStart, firstDur, secondStart, secondDur) => {
        let ans = Infinity;

        for (let i = 0; i < firstStart.length; i++) {
            const finishFirst = firstStart[i] + firstDur[i];

            for (let j = 0; j < secondStart.length; j++) {
                const startSecond = Math.max(
                    finishFirst,
                    secondStart[j]
                );

                const finishSecond =
                    startSecond + secondDur[j];

                ans = Math.min(ans, finishSecond);
            }
        }

        return ans;
    };

    return Math.min(
        calc(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        ),
        calc(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        )
    );
};
