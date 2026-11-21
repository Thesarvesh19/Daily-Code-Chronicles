class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        vector<tuple<int, bool, int>> st;
        st.push_back({0, true, -1});

        while (!st.empty()) {
            auto [u, entering, prev] = st.back();
            st.pop_back();

            int c = s[u] - 'a';

            if (entering) {
                prev = last[c];

                if (u != 0 && last[c] != -1)
                    newParent[u] = last[c];

                last[c] = u;

                st.push_back({u, false, prev});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--)
                    st.push_back({adj[u][i], true, -1});
            } else {
                last[c] = prev;
            }
        }

        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; i++)
            newAdj[newParent[i]].push_back(i);

        vector<int> order = {0};

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            for (int v : newAdj[u])
                order.push_back(v);
        }

        vector<int> ans(n, 1);

        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            for (int v : newAdj[u])
                ans[u] += ans[v];
        }

        return ans;
    }
};
