class Solution {
public:
    string s;
    pair<long long,long long> dp[20][11][11][2];
    bool vis[20][11][11][2];

    pair<long long,long long> dfs(
        int pos,
        int prev,
        int prev2,
        bool lead,
        bool tight
    ) {
        if (pos == s.size()) return {1,0};

        if (!tight && vis[pos][prev+1][prev2+1][lead])
            return dp[pos][prev+1][prev2+1][lead];

        int lim = tight ? s[pos]-'0' : 9;

        long long cnt = 0;
        long long wav = 0;

        for(int d=0; d<=lim; d++) {

            bool ntight = tight && d==lim;
            bool nlead = lead && d==0;

            auto res = dfs(
                pos+1,
                nlead ? -1 : d,
                prev,
                nlead,
                ntight
            );

            cnt += res.first;

            if(!lead &&
               prev2!=-1 &&
               ((prev2<prev && prev>d) ||
                (prev2>prev && prev<d)))
                wav += res.first;

            wav += res.second;
        }

        if(!tight){
            vis[pos][prev+1][prev2+1][lead]=true;
            dp[pos][prev+1][prev2+1][lead]={cnt,wav};
        }

        return {cnt,wav};
    }

    long long solve(long long x){
        if(x<=0) return 0;
        s=to_string(x);
        memset(vis,0,sizeof(vis));
        return dfs(0,-1,-1,true,true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2)-solve(num1-1);
    }
};
