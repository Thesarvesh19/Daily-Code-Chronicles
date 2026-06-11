public class Solution
{
    private const long MOD = 1_000_000_007;

    private long ModPow(long a, long b)
    {
        long res = 1;

        while (b > 0)
        {
            if ((b & 1) == 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    public int AssignEdgeWeights(int[][] edges)
    {
        int n = edges.Length + 1;

        List<int>[] g = new List<int>[n + 1];
        for (int i = 0; i <= n; i++)
            g[i] = new List<int>();

        foreach (var e in edges)
        {
            g[e[0]].Add(e[1]);
            g[e[1]].Add(e[0]);
        }

        Queue<int> q = new Queue<int>();
        bool[] vis = new bool[n + 1];

        q.Enqueue(1);
        vis[1] = true;

        int depth = -1;

        while (q.Count > 0)
        {
            int sz = q.Count;
            depth++;

            while (sz-- > 0)
            {
                int u = q.Dequeue();

                foreach (int v in g[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.Enqueue(v);
                    }
                }
            }
        }

        return (int)ModPow(2, depth - 1);
    }
}
