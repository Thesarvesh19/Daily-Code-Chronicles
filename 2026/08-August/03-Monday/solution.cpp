class Solution {
public:
    vector<int> memo;
    vector<int> stoneValue;
    int n;

    int dfs(int i) {
        if (i >= n)
            return 0;

        if (memo[i] != INT_MIN)
            return memo[i];

        int best = INT_MIN;
        int sum = 0;

        for (int j = i; j < min(i + 3, n); j++) {
            sum += stoneValue[j];
            best = max(best, sum - dfs(j + 1));
        }

        return memo[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        this->stoneValue = stoneValue;
        n = stoneValue.size();
        memo.assign(n, INT_MIN);

        int diff = dfs(0);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};
