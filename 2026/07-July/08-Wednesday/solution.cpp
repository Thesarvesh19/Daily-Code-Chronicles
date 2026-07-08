class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007LL;

        int n = s.size();

        vector<int> digits;
        vector<int> positions;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                positions.push_back(i);
            }
        }

        int m = digits.size();
        vector<int> ans(queries.size(), 0);

        if (m == 0)
            return ans;

        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            power10[i] = (power10[i - 1] * 10) % MOD;

        vector<long long> prefixValue(m + 1, 0);
        vector<long long> prefixSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefixValue[i + 1] = (prefixValue[i] * 10 + digits[i]) % MOD;
            prefixSum[i + 1] = prefixSum[i] + digits[i];
        }

        vector<int> first(n + 1, m);

        int idx = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (idx >= 0 && positions[idx] == i) {
                first[i] = idx;
                idx--;
            } else {
                first[i] = first[i + 1];
            }
        }

        vector<int> last(n, -1);

        idx = 0;
        int current = -1;

        for (int i = 0; i < n; i++) {
            if (idx < m && positions[idx] == i) {
                current = idx;
                idx++;
            }
            last[i] = current;
        }

        for (int i = 0; i < (int)queries.size(); i++) {
            int left = first[queries[i][0]];
            int right = last[queries[i][1]];

            if (left > right || left == m || right == -1) {
                ans[i] = 0;
                continue;
            }

            int len = right - left + 1;

            long long number =
                (prefixValue[right + 1] -
                 (prefixValue[left] * power10[len]) % MOD +
                 MOD) % MOD;

            long long digitSum = prefixSum[right + 1] - prefixSum[left];

            ans[i] = (number * digitSum) % MOD;
        }

        return ans;
    }
};
