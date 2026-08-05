class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n), undirected(n);

        for (auto& e : invocations) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            undirected[u].push_back(v);
            undirected[v].push_back(u);
        }

        vector<bool> suspicious(n, false), visited(n, false);

        auto dfs = [&](auto&& self, int u) -> void {
            suspicious[u] = true;
            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    self(self, v);
                }
            }
        };

        dfs(dfs, k);

        auto dfs2 = [&](auto&& self, int u) -> void {
            visited[u] = true;
            for (int v : undirected[u]) {
                if (!visited[v]) {
                    suspicious[v] = false;
                    self(self, v);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !visited[i]) {
                dfs2(dfs2, i);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
