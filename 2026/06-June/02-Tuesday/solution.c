int calc(int* firstStart, int firstSize,
         int* firstDur,
         int* secondStart, int secondSize,
         int* secondDur) {

    int ans = INT_MAX;

    for (int i = 0; i < firstSize; i++) {
        int finishFirst = firstStart[i] + firstDur[i];

        for (int j = 0; j < secondSize; j++) {
            int startSecond =
                (finishFirst > secondStart[j])
                ? finishFirst
                : secondStart[j];

            int finishSecond =
                startSecond + secondDur[j];

            if (finishSecond < ans) {
                ans = finishSecond;
            }
        }
    }

    return ans;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize) {

    int landToWater = calc(
        landStartTime,
        landStartTimeSize,
        landDuration,
        waterStartTime,
        waterStartTimeSize,
        waterDuration
    );

    int waterToLand = calc(
        waterStartTime,
        waterStartTimeSize,
        waterDuration,
        landStartTime,
        landStartTimeSize,
        landDuration
    );

    return (landToWater < waterToLand)
           ? landToWater
           : waterToLand;
}
