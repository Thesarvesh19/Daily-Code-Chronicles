class Solution {
    static constexpr int MOD = 1'000'000'007;
    static constexpr int LOG = 17;

    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> g;

    void dfs(int u, int p) {
        up[0][u] = p;

        for (int v : g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k))
                a = up[k][a];
        }

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return up[0][a];
    }

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        g.assign(n + 1, {});
        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1, 0));

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 0);

        for (int k = 1; k < LOG; k++) {
            for (int v = 1; v <= n; v++) {
                up[k][v] = up[k - 1][up[k - 1][v]];
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int w = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[w];

            ans.push_back((int)modPow(2, dist - 1));
        }

        return ans;
    }
};
