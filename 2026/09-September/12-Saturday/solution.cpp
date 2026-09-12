class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start time
        sort(a.begin(), a.end());

        vector<long long> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        // next[i] = first interval with start > a[i].end
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        // dp[i][k] = best result from i onward
        // with at most k intervals.
        //
        // Store {score, indices}
        struct State {
            long long score;
            vector<int> indices;
        };

        vector<vector<State>> dp(n + 1, vector<State>(5));
        vector<vector<bool>> vis(n + 1, vector<bool>(5, false));

        function<State(int, int)> solve = [&](int i, int k) -> State {
            if (i >= n || k == 0)
                return {0, {}};

            if (vis[i][k])
                return dp[i][k];

            vis[i][k] = true;

            // Option 1: skip current interval
            State skip = solve(i + 1, k);

            // Option 2: take current interval
            State take = solve(nxt[i], k - 1);
            take.score += a[i][2];
            take.indices.push_back((int)a[i][3]);

            // Keep indices sorted for lexicographical comparison
            sort(take.indices.begin(), take.indices.end());

            State ans;

            if (take.score > skip.score) {
                ans = take;
            } 
            else if (take.score < skip.score) {
                ans = skip;
            } 
            else {
                // Same score -> lexicographically smaller indices
                if (take.indices < skip.indices)
                    ans = take;
                else
                    ans = skip;
            }

            return dp[i][k] = ans;
        };

        return solve(0, 4).indices;
    }
};
