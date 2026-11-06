class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(queries.size());
        unordered_map<int, int> active;

        int left = 0, right = 0;

        for (auto [q, idx] : sortedQueries) {

            while (right < logs.size() && logs[right][1] <= q) {
                active[logs[right][0]]++;
                right++;
            }

            while (left < right && logs[left][1] < q - x) {
                int server = logs[left][0];

                active[server]--;

                if (active[server] == 0) {
                    active.erase(server);
                }

                left++;
            }

            ans[idx] = n - active.size();
        }

        return ans;
    }
};
