import java.util.*;

class Solution {

    static class State {
        long score;
        List<Integer> indices;

        State(long score, List<Integer> indices) {
            this.score = score;
            this.indices = indices;
        }
    }

    private int[][] intervals;
    private int[] next;
    private State[][] dp;
    private boolean[][] visited;

    public int[] maximumWeight(List<List<Integer>> input) {
        int n = input.size();

        // {start, end, weight, original index}
        intervals = new int[n][4];

        for (int i = 0; i < n; i++) {
            intervals[i][0] = input.get(i).get(0);
            intervals[i][1] = input.get(i).get(1);
            intervals[i][2] = input.get(i).get(2);
            intervals[i][3] = i;
        }

        // Sort by start time
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] != b[0])
                return Integer.compare(a[0], b[0]);

            if (a[1] != b[1])
                return Integer.compare(a[1], b[1]);

            return Integer.compare(a[3], b[3]);
        });

        int[] starts = new int[n];

        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        // Find first interval with start > current end
        next = new int[n];

        for (int i = 0; i < n; i++) {
            next[i] = upperBound(starts, intervals[i][1]);
        }

        dp = new State[n + 1][5];
        visited = new boolean[n + 1][5];

        State result = solve(0, 4);

        int[] answer = new int[result.indices.size()];

        for (int i = 0; i < result.indices.size(); i++) {
            answer[i] = result.indices.get(i);
        }

        return answer;
    }

    private State solve(int i, int k) {
        if (i >= intervals.length || k == 0) {
            return new State(0, new ArrayList<>());
        }

        if (visited[i][k])
            return dp[i][k];

        visited[i][k] = true;

        // Option 1: Skip current interval
        State skip = solve(i + 1, k);

        // Option 2: Take current interval
        State take = solve(next[i], k - 1);

        List<Integer> takeIndices = new ArrayList<>(take.indices);
        takeIndices.add(intervals[i][3]);
        Collections.sort(takeIndices);

        State takeState = new State(
            take.score + intervals[i][2],
            takeIndices
        );

        State answer;

        if (takeState.score > skip.score) {
            answer = takeState;
        } 
        else if (takeState.score < skip.score) {
            answer = skip;
        } 
        else {
            // Same score -> lexicographically smaller indices
            if (lexicographicallySmaller(
                    takeState.indices,
                    skip.indices)) {
                answer = takeState;
            } else {
                answer = skip;
            }
        }

        return dp[i][k] = answer;
    }

    private int upperBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    private boolean lexicographicallySmaller(
            List<Integer> a,
            List<Integer> b) {

        int n = Math.min(a.size(), b.size());

        for (int i = 0; i < n; i++) {
            if (!a.get(i).equals(b.get(i))) {
                return a.get(i) < b.get(i);
            }
        }

        return a.size() < b.size();
    }
}
