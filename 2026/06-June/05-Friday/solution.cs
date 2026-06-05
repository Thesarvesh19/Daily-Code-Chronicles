public class Solution
{
    string s;
    Dictionary<string,(long,long)> memo;

    (long,long) DFS(
        int pos,
        int prev,
        int prev2,
        bool lead,
        bool tight)
    {
        if(pos==s.Length)
            return (1,0);

        string key =
            pos + "|" + prev + "|" +
            prev2 + "|" + lead;

        if(!tight && memo.ContainsKey(key))
            return memo[key];

        int limit = tight ? s[pos]-'0' : 9;

        long cnt = 0;
        long wav = 0;

        for(int d=0; d<=limit; d++)
        {
            bool ntight = tight && d==limit;
            bool nlead = lead && d==0;

            var res = DFS(
                pos+1,
                nlead ? -1 : d,
                prev,
                nlead,
                ntight
            );

            cnt += res.Item1;

            if(!lead &&
               prev2!=-1 &&
               ((prev2<prev && prev>d) ||
                (prev2>prev && prev<d)))
                wav += res.Item1;

            wav += res.Item2;
        }

        if(!tight)
            memo[key]=(cnt,wav);

        return (cnt,wav);
    }

    long Solve(long x)
    {
        if(x<=0) return 0;

        s=x.ToString();
        memo=new Dictionary<string,(long,long)>();

        return DFS(0,-1,-1,true,true).Item2;
    }

    public long TotalWaviness(long num1,long num2)
    {
        return Solve(num2)-Solve(num1-1);
    }
}
