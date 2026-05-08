import java.util.*;

class Solution {

    public int[] smallestPrimeFactor(int limit) {
        int[] spf = new int[limit + 1];

        for (int i = 0; i <= limit; i++) {
            spf[i] = i;
        }

        for (long i = 2; i * i <= limit; i++) {
            if (spf[(int)i] == i) {
                for (long j = i * i; j <= limit; j += i) { 
                    if (spf[(int)j] == j) {
                        spf[(int)j] = (int)i;
                    }
                }
            }
        }

        return spf;
    }

    public int minJumps(int[] nums) {
        int n = nums.length;

        if (n == 1) {
            return 0;
        }

        int mx = 0;
        for (int x : nums) {
            mx = Math.max(mx, x);
        }

        int[] spf = smallestPrimeFactor(mx);

        Map<Integer, List<Integer>> bucket = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                bucket.putIfAbsent(p, new ArrayList<>());
                bucket.get(p).add(i);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        int[] dist = new int[n];
        Arrays.fill(dist, -1);

        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        dist[0] = 0;

        Set<Integer> usedPrime = new HashSet<>();

        while (!q.isEmpty()) {
            int i = q.poll();

            if (i == n - 1) {
                return dist[i];
            }

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.offer(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.offer(i + 1);
            }

            int val = nums[i];

            if (val > 1 && spf[val] == val && !usedPrime.contains(val)) {
                usedPrime.add(val);

                for (int nxt : bucket.getOrDefault(val, new ArrayList<>())) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[i] + 1;
                        q.offer(nxt);
                    }
                }
            }
        }

        return -1;
    }
}
