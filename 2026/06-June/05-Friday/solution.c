#include <string.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    ll cnt;
    ll wav;
} Node;

char s[25];
Node dp[20][11][11][2];
bool vis[20][11][11][2];

Node dfs(int pos, int prev, int prev2, int lead, int tight) {
    if (pos == (int)strlen(s)) {
        Node base = {1, 0};
        return base;
    }

    if (!tight && vis[pos][prev + 1][prev2 + 1][lead]) {
        return dp[pos][prev + 1][prev2 + 1][lead];
    }

    int limit = tight ? s[pos] - '0' : 9;

    ll cnt = 0;
    ll wav = 0;

    for (int d = 0; d <= limit; d++) {
        int ntight = tight && (d == limit);
        int nlead = lead && (d == 0);

        Node res = dfs(
            pos + 1,
            nlead ? -1 : d,
            prev,
            nlead,
            ntight
        );

        cnt += res.cnt;

        if (!lead &&
            prev2 != -1 &&
            ((prev2 < prev && prev > d) ||
             (prev2 > prev && prev < d))) {
            wav += res.cnt;
        }

        wav += res.wav;
    }

    Node ans = {cnt, wav};

    if (!tight) {
        vis[pos][prev + 1][prev2 + 1][lead] = true;
        dp[pos][prev + 1][prev2 + 1][lead] = ans;
    }

    return ans;
}

ll solve(ll x) {
    if (x <= 0) return 0;

    sprintf(s, "%lld", x);
    memset(vis, 0, sizeof(vis));

    return dfs(0, -1, -1, 1, 1).wav;
}

long long totalWaviness(long long num1, long long num2) {
    return solve(num2) - solve(num1 - 1);
}
