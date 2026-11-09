import java.util.*;

class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {

        TreeSet<Integer> available = new TreeSet<>();
        PriorityQueue<int[]> busy = new PriorityQueue<>(
            (a, b) -> Integer.compare(a[0], b[0])
        );

        int[] count = new int[k];

        for (int i = 0; i < k; i++) {
            available.add(i);
        }

        for (int i = 0; i < arrival.length; i++) {

            int start = arrival[i];

            // Release servers whose requests have finished
            while (!busy.isEmpty() && busy.peek()[0] <= start) {
                int[] finished = busy.poll();
                available.add(finished[1]);
            }

            // No available server
            if (available.isEmpty()) {
                continue;
            }

            // Find the first available server >= i % k
            int target = i % k;

            Integer server = available.ceiling(target);

            // Wrap around if necessary
            if (server == null) {
                server = available.first();
            }

            // Assign request
            available.remove(server);
            count[server]++;

            // Add server to busy heap
            busy.offer(new int[]{
                start + load[i],
                server
            });
        }

        // Find maximum number of requests handled
        int maxCount = 0;

        for (int c : count) {
            maxCount = Math.max(maxCount, c);
        }

        // Collect all busiest servers
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            if (count[i] == maxCount) {
                result.add(i);
            }
        }

        return result;
    }
}
