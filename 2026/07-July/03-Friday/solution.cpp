class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> g(n);

        int l = INT_MAX, r = 0;

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (!online[u] || !online[v]) continue;
            g[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }

        auto check = [&](int mid) -> bool {
            vector<long long> dist(n, LLONG_MAX / 4);
            dist[0] = 0;

            priority_queue<pair<long long,int>,
                           vector<pair<long long,int>>,
                           greater<pair<long long,int>>> pq;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > k) return false;
                if (u == n - 1) return true;
                if (d > dist[u]) continue;

                for (auto& [v, w] : g[u]) {
                    if (w < mid) continue;
                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return false;
        };

        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }

        return check(l) ? l : -1;
    }
};
