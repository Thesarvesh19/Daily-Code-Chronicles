import java.util.*;

class SegmentTree {
    int n;
    int[] tree;

    SegmentTree(int n) { 
        this.n = n;
        tree = new int[4 * n];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;

        return Math.max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }
}

class Solution {
    public List<Boolean> getResults(int[][] queries) {
        int MAX = 50000;

        TreeSet<Integer> obstacles = new TreeSet<>();
        obstacles.add(0);

        SegmentTree seg = new SegmentTree(MAX + 1);

        List<Boolean> ans = new ArrayList<>();

        for (int[] q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                Integer left = obstacles.floor(x);
                Integer right = obstacles.ceiling(x);

                obstacles.add(x);

                seg.update(1, 0, MAX, x, x - left);

                if (right != null) {
                    seg.update(1, 0, MAX, right, right - x);
                }

            } else {

                int x = q[1];
                int sz = q[2];

                Integer prev = obstacles.floor(x);

                int best = seg.query(1, 0, MAX, 0, prev);

                ans.add(
                    best >= sz ||
                    x - prev >= sz
                );
            }
        }

        return ans;
    }
}
