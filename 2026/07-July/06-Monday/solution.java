import java.util.*;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {

        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(b[1], a[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        int answer = 0;
        int farthest = -1;

        for (int[] current : intervals) {
            if (current[1] > farthest) {
                answer++;
                farthest = current[1];
            }
        }

        return answer;
    }
}
