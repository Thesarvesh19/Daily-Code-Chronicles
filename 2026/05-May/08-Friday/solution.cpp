class Solution {
public:
    vector<int> smallestPrimeFactor(int limit) {
        vector<int> spf(limit + 1);

        for (int i = 0; i <= limit; i++) {
            spf[i] = i;
        }

        for (long long i = 2; i * i <= limit; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= limit; j += i) {
                    if (spf[j] == j) { 
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf = smallestPrimeFactor(mx);

        unordered_map<int, vector<int>> bucket;

        // Store indices for every prime factor
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                bucket[p].push_back(i);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1) {
                return d;
            }

            // Move left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // Move right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            // Teleport only if current value is prime
            if (val > 1 && spf[val] == val && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for (int nxt : bucket[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        return -1;
    }
};
