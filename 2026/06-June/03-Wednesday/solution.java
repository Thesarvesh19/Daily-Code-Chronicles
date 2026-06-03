import java.util.*;

class Solution {

    private long solve(int[] s1, int[] d1,
                       int[] s2, int[] d2) {

        int m = s2.length;

        long[][] rides = new long[m][2];

        for (int i = 0; i < m; i++) {
            rides[i][0] = s2[i];
            rides[i][1] = d2[i];
        }

        Arrays.sort(rides, (a, b) -> Long.compare(a[0], b[0]));

        long[] start = new long[m];
        long[] prefDur = new long[m];
        long[] sufFinish = new long[m];

        for (int i = 0; i < m; i++) {
            start[i] = rides[i][0];
        }

        prefDur[0] = rides[0][1];

        for (int i = 1; i < m; i++) {
            prefDur[i] = Math.min(prefDur[i - 1], rides[i][1]);
        }

        sufFinish[m - 1] = rides[m - 1][0] + rides[m - 1][1];

        for (int i = m - 2; i >= 0; i--) {
            sufFinish[i] = Math.min(
                sufFinish[i + 1],
                rides[i][0] + rides[i][1]
            );
        }

        long ans = Long.MAX_VALUE;

        for (int i = 0; i < s1.length; i++) {

            long finish1 = (long) s1[i] + d1[i];

            int pos = lowerBound(start, finish1);

            if (pos > 0) {
                ans = Math.min(
                    ans,
                    finish1 + prefDur[pos - 1]
                );
            }

            if (pos < m) {
                ans = Math.min(
                    ans,
                    sufFinish[pos]
                );
            }
        }

        return ans;
    }

    private int lowerBound(long[] arr, long target) {
        int l = 0;
        int r = arr.length;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    public int earliestFinishTime(int[] landStartTime,
                                  int[] landDuration,
                                  int[] waterStartTime,
                                  int[] waterDuration) {

        long ans = Math.min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        );

        return (int) ans;
    }
}
