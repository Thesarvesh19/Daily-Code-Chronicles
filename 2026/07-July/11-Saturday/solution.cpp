class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            stack<int> st;
            st.push(i);
            visited[i] = true;

            int nodes = 0;
            int degreeSum = 0;

            while (!st.empty()) {
                int cur = st.top();
                st.pop();

                nodes++;
                degreeSum += graph[cur].size();

                for (int nxt : graph[cur]) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        st.push(nxt);
                    }
                }
            }

            if (degreeSum / 2 == nodes * (nodes - 1) / 2)
                answer++;
        }

        return answer;
    }
};
