class Solution {
    private int calc(int[] firstStart, int[] firstDur,
                     int[] secondStart, int[] secondDur) {

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < firstStart.length; i++) {
            int finishFirst = firstStart[i] + firstDur[i];

            for (int j = 0; j < secondStart.length; j++) {
                int startSecond = Math.max(finishFirst, secondStart[j]);
                int finishSecond = startSecond + secondDur[j];

                ans = Math.min(ans, finishSecond);
            }
        }

        return ans;
    }

    public int earliestFinishTime(int[] landStartTime,
                                  int[] landDuration,
                                  int[] waterStartTime,
                                  int[] waterDuration) {

        return Math.min(
            calc(landStartTime, landDuration,
                 waterStartTime, waterDuration),

            calc(waterStartTime, waterDuration,
                 landStartTime, landDuration)
        );
    }
}
