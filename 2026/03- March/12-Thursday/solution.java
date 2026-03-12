import java.util.*;

class Solution {

    public int maxStability(int n, int[][] edges, int k) {

        int[] dsuParent = new int[n];
        int[] dsuRank = new int[n];

        for (int i = 0; i < n; i++) {
            dsuParent[i] = i;
        }

        int mandatoryCount = 0;

        for (int[] e : edges) {
            int u = e[0], v = e[1], s = e[2], m = e[3];

            if (m == 1) {
                if (!union0(u, v, dsuParent, dsuRank)) {
                    return -1;
                }
                mandatoryCount++;
            }
        }

        if (mandatoryCount > n - 1) {
            return -1;
        }

        int lo = 0, hi = 200000;
        int ans = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (can(mid, n, edges, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }

    private boolean can(int x, int n, int[][] edges, int k) {

        int[] parent = new int[n];
        int[] rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int upgrades = 0;
        int edgesUsed = 0;

        for (int[] e : edges) {
            int u = e[0], v = e[1], s = e[2], m = e[3];

            if (m == 1) {
                if (s < x) return false;

                if (union(u, v, parent, rank)) {
                    edgesUsed++;
                }
            }
        }

        List<int[]> optional = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0], v = e[1], s = e[2], m = e[3];

            if (m == 0) {
                if (s >= x) {
                    optional.add(new int[]{0, u, v});
                } else if (s * 2 >= x) {
                    optional.add(new int[]{1, u, v});
                }
            }
        }

        optional.sort(Comparator.comparingInt(a -> a[0]));

        for (int[] e : optional) {
            int cost = e[0], u = e[1], v = e[2];

            if (union(u, v, parent, rank)) {
                edgesUsed++;
                upgrades += cost;

                if (upgrades > k) return false;

                if (edgesUsed == n - 1) return true;
            }
        }

        return edgesUsed == n - 1 && upgrades <= k;
    }

    private int find(int x, int[] parent) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    private boolean union(int a, int b, int[] parent, int[] rank) {

        int ra = find(a, parent);
        int rb = find(b, parent);

        if (ra == rb) return false;

        if (rank[ra] < rank[rb]) {
            parent[ra] = rb;
        } else if (rank[ra] > rank[rb]) {
            parent[rb] = ra;
        } else {
            parent[rb] = ra;
            rank[ra]++;
        }

        return true;
    }

    private int find0(int x, int[] parent) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    private boolean union0(int a, int b, int[] parent, int[] rank) {

        int ra = find0(a, parent);
        int rb = find0(b, parent);

        if (ra == rb) return false;

        if (rank[ra] < rank[rb]) {
            parent[ra] = rb;
        } else if (rank[ra] > rank[rb]) {
            parent[rb] = ra;
        } else {
            parent[rb] = ra;
            rank[ra]++;
        }

        return true;
    }
}
