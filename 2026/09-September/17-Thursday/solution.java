import java.util.*;

class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int INF = 1_000_000_000;

        // Prefix sum -> latest index
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);

        // best[i] = minimum length of a valid subarray
        // completely inside the first i elements
        int[] best = new int[n + 1];
        Arrays.fill(best, INF);

        int sum = 0;
        int ans = INF;

        for (int i = 1; i <= n; i++) {
            sum += arr[i - 1];

            // Carry forward the previous best
            best[i] = best[i - 1];

            // We need an earlier prefix sum of sum - target
            if (map.containsKey(sum - target)) {
                int j = map.get(sum - target);

                // Subarray [j, i-1] has sum = target
                int len = i - j;

                // best[j] is completely before this subarray,
                // so they do not overlap
                if (best[j] != INF) {
                    ans = Math.min(ans, best[j] + len);
                }

                // Update best for the current prefix
                best[i] = Math.min(best[i], len);
            }

            // Store latest occurrence of this prefix sum
            map.put(sum, i);
        }

        return ans == INF ? -1 : ans;
    }
}
