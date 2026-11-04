import java.util.*;

class Solution {
    public long minOperations(int[] nums, int x, int k) {
        int n = nums.length;

        PriorityQueue<Integer> small =
            new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> large =
            new PriorityQueue<>();

        Map<Integer, Integer> delayed = new HashMap<>();

        long[] sums = new long[2];

        int[] sizes = new int[2];

        class MedianWindow {
            void prune(PriorityQueue<Integer> heap, boolean isSmall) {
                while (!heap.isEmpty()) {
                    int val = heap.peek();
                    if (isSmall) val = -val;

                    if (delayed.getOrDefault(val, 0) == 0) break;

                    delayed.put(val, delayed.get(val) - 1);
                    heap.poll();
                }
            }

            void rebalance() {
                while (sizes[0] > sizes[1] + 1) {
                    prune(small, true);
                    int val = small.poll();

                    large.offer(val);
                    sizes[0]--;
                    sizes[1]++;
                    sums[0] -= val;
                    sums[1] += val;
                }

                while (sizes[0] < sizes[1]) {
                    prune(large, false);
                    int val = large.poll();

                    small.offer(val);
                    sizes[1]--;
                    sizes[0]++;
                    sums[1] -= val;
                    sums[0] += val;
                }
            }

            void add(int val) {
                prune(small, true);

                if (small.isEmpty() || val <= small.peek()) {
                    small.offer(val);
                    sizes[0]++;
                    sums[0] += val;
                } else {
                    large.offer(val);
                    sizes[1]++;
                    sums[1] += val;
                }

                rebalance();
            }

            void remove(int val) {
                prune(small, true);
                prune(large, false);

                delayed.put(val, delayed.getOrDefault(val, 0) + 1);

                if (val <= small.peek()) {
                    sizes[0]--;
                    sums[0] -= val;

                    if (val == small.peek()) {
                        prune(small, true);
                    }
                } else {
                    sizes[1]--;
                    sums[1] -= val;

                    if (!large.isEmpty() && val == large.peek()) {
                        prune(large, false);
                    }
                }

                rebalance();
            }

            long getCost() {
                prune(small, true);

                long median = small.peek();

                return median * sizes[0] - sums[0]
                     + sums[1] - median * sizes[1];
            }
        }

        MedianWindow window = new MedianWindow();

        long[] costs = new long[n - x + 1];

        for (int i = 0; i < n; i++) {
            window.add(nums[i]);

            if (i >= x) {
                window.remove(nums[i - x]);
            }

            if (i >= x - 1) {
                costs[i - x + 1] = window.getCost();
            }
        }

        long INF = Long.MAX_VALUE / 4;

        long[] prev = new long[n + 1];
        long[] curr = new long[n + 1];

        for (int j = 1; j <= k; j++) {
            Arrays.fill(curr, INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = Math.min(
                        curr[i],
                        prev[i - x] + costs[i - x]
                    );
                }
            }

            long[] temp = prev;
            prev = curr;
            curr = temp;
        }

        return prev[n];
    }
}
