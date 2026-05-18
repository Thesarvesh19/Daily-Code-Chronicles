class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        // Store all indices having same value
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int curr = q.front();
                q.pop();

                if(curr == n - 1)
                    return steps;

                vector<int> next = mp[arr[curr]];

                // adjacent indices
                next.push_back(curr - 1);
                next.push_back(curr + 1);

                for(int idx : next) {
                    if(idx >= 0 && idx < n && !visited[idx]) {
                        visited[idx] = true;
                        q.push(idx);
                    }
                }

                // clear to avoid reprocessing
                mp[arr[curr]].clear();
            }

            steps++;
        }

        return -1;
    }
};
