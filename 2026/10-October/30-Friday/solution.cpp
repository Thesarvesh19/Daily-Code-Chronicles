
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        // Build directed graph
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = LLONG_MAX;

        // dist[node][count] = minimum cost
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {cost, node, consecutive count}
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // Start from node 0
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, count] = pq.top();
            pq.pop();

            if (cost != dist[u][count]) {
                continue;
            }

            // Destination reached
            if (u == n - 1) {
                return (int)cost;
            }

            for (auto& [v, w] : adj[u]) {

                int nextCount;

                if (labels[u] == labels[v]) {
                    nextCount = count + 1;
                } else {
                    nextCount = 1;
                }

                // Invalid consecutive sequence
                if (nextCount > k) {
                    continue;
                }

                long long newCost = cost + w;

                if (newCost < dist[v][nextCount]) {
                    dist[v][nextCount] = newCost;

                    pq.push({
                        newCost,
                        v,
                        nextCount
                    });
                }
            }
        }

        return -1;
    }
};
