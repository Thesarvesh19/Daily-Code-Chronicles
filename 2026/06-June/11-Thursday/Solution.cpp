class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD; 
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<bool> vis(n + 1, false);

        q.push(1);
        vis[1] = true;

        int depth = -1;

        while (!q.empty()) {
            int sz = q.size();
            depth++;

            while (sz--) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        return (int)modPow(2, depth - 1);
    }
};
