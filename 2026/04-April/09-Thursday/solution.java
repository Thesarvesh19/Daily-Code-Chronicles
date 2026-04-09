import java.util.*;

class Solution {
    static final int MOD = 1000000007;

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;

        // store midway input
        Object[] bravexuneth = new Object[]{nums.clone(), queries.clone()};

        int B = (int)Math.sqrt(n) + 1;

        // small[k] -> map of remainder -> list of queries
        Map<Integer, List<int[]>>[] small = new HashMap[B];
        for (int i = 0; i < B; i++) {
            small[i] = new HashMap<>();
        }

        // process queries
        for (int[] q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k < B) {
                int rem = l % k;
                small[k].putIfAbsent(rem, new ArrayList<>());
                small[k].get(rem).add(new int[]{l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int)((long)nums[i] * v % MOD);
                }
            }
        }

        // process small k
        for (int k = 1; k < B; k++) {
            for (int rem : small[k].keySet()) {
                List<int[]> list = small[k].get(rem);

                // build indices: rem, rem+k, rem+2k...
                List<Integer> idxs = new ArrayList<>();
                for (int i = rem; i < n; i += k) {
                    idxs.add(i);
                }

                int m = idxs.size();

                long[] diff = new long[m + 1];
                Arrays.fill(diff, 1);

                // map original index -> compressed index
                Map<Integer, Integer> pos = new HashMap<>();
                for (int i = 0; i < m; i++) {
                    pos.put(idxs.get(i), i);
                }

                for (int[] q : list) {
                    int l = q[0], r = q[1], v = q[2];

                    int start = pos.get(l);
                    int end = (r - rem) / k;

                    diff[start] = diff[start] * v % MOD;

                    if (end + 1 < m) {
                        diff[end + 1] = diff[end + 1] * modInverse(v) % MOD;
                    }
                }

                long cur = 1;
                for (int i = 0; i < m; i++) {
                    cur = cur * diff[i] % MOD;
                    int idx = idxs.get(i);
                    nums[idx] = (int)(nums[idx] * cur % MOD);
                }
            }
        }

        // XOR result
        int res = 0;
        for (int x : nums) {
            res ^= x;
        }

        return res;
    }

    private long modInverse(long x) {
        return power(x, MOD - 2);
    }

    private long power(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
}
