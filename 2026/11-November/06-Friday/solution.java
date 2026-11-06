import java.util.*;

class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {

        Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));

        int k = queries.length;

        int[][] sortedQueries = new int[k][2];

        for (int i = 0; i < k; i++) {
            sortedQueries[i][0] = queries[i];
            sortedQueries[i][1] = i;
        }

        Arrays.sort(sortedQueries, (a, b) -> Integer.compare(a[0], b[0]));

        int[] ans = new int[k];

        HashMap<Integer, Integer> active = new HashMap<>();

        int left = 0, right = 0;

        for (int[] query : sortedQueries) {

            int q = query[0];
            int idx = query[1];

            while (right < logs.length && logs[right][1] <= q) {
                int server = logs[right][0];
                active.put(server, active.getOrDefault(server, 0) + 1);
                right++;
            }

            while (left < right && logs[left][1] < q - x) {

                int server = logs[left][0];

                int count = active.get(server) - 1;

                if (count == 0) {
                    active.remove(server);
                } else {
                    active.put(server, count);
                }

                left++;
            }

            ans[idx] = n - active.size();
        }

        return ans;
    }
}
