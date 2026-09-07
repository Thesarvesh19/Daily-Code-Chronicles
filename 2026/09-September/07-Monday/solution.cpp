#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long dp = 0;
        vector<long long> last(26, 0);

        for (char ch : s) {
            long long newDp = (2 * dp + 1) % MOD;

            int idx = ch - 'a';
            newDp = (newDp - last[idx] + MOD) % MOD;

            last[idx] = (dp + 1) % MOD;
            dp = newDp;
        }

        return dp;
    }
};
