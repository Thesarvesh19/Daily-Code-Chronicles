class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> ancestors;

        function<void(int)> dfs = [&](int u) {
            ancestors.push_back(u);

            for (int v : adj[u]) {
                for (int i = (int)ancestors.size() - 2; i >= 0; i--) {
                    int a = ancestors[i];
                    if (s[a] == s[v]) {
                        newParent[v] = a;
                        break;
                    }
                }
                dfs(v);
            }

            ancestors.pop_back();
        };

        dfs(0);

        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        function<int(int)> calc = [&](int u) {
            ans[u] = 1;
            for (int v : newAdj[u]) {
                ans[u] += calc(v);
            }
            return ans[u];
        };

        calc(0);
        return ans;
    }
};
