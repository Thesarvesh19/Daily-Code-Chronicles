using System;
using System.Collections.Generic;

public class Solution
{
    public int FindMaxPathScore(int[][] edges, bool[] online, long k)
    {
        int n = online.Length;
        List<(int, int)>[] graph = new List<(int, int)>[n];

        for (int i = 0; i < n; i++)
            graph[i] = new List<(int, int)>();

        int lo = int.MaxValue;
        int hi = 0;

        foreach (var e in edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (!online[u] || !online[v])
                continue;

            graph[u].Add((v, w));

            lo = Math.Min(lo, w);
            hi = Math.Max(hi, w);
        }

        bool Check(int mid)
        {
            long[] dist = new long[n];
            Array.Fill(dist, long.MaxValue / 4);

            var pq = new PriorityQueue<int, long>();

            dist[0] = 0;
            pq.Enqueue(0, 0);

            while (pq.Count > 0)
            {
                pq.TryDequeue(out int u, out long d);

                if (d > k)
                    return false;

                if (u == n - 1)
                    return true;

                if (d != dist[u])
                    continue;

                foreach (var (v, w) in graph[u])
                {
                    if (w < mid)
                        continue;

                    long nd = d + w;

                    if (nd < dist[v])
                    {
                        dist[v] = nd;
                        pq.Enqueue(v, nd);
                    }
                }
            }

            return false;
        }

        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;

            if (Check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        return Check(lo) ? lo : -1;
    }
}
