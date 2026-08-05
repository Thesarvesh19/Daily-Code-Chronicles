using System;
using System.Collections.Generic;

public class Solution
{
    public IList<int> RemainingMethods(int n, int k, int[][] invocations)
    {
        List<int>[] graph = new List<int>[n];
        List<int>[] undirected = new List<int>[n];

        for (int i = 0; i < n; i++)
        {
            graph[i] = new List<int>();
            undirected[i] = new List<int>();
        }

        foreach (var edge in invocations)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].Add(v);
            undirected[u].Add(v);
            undirected[v].Add(u);
        }

        bool[] suspicious = new bool[n];
        DFS(k, graph, suspicious);

        bool[] visited = new bool[n];

        for (int i = 0; i < n; i++)
        {
            if (!suspicious[i] && !visited[i])
            {
                DFS2(i, undirected, suspicious, visited);
            }
        }

        List<int> ans = new List<int>();

        for (int i = 0; i < n; i++)
        {
            if (!suspicious[i])
                ans.Add(i);
        }

        return ans;
    }

    private void DFS(int node, List<int>[] graph, bool[] suspicious)
    {
        suspicious[node] = true;

        foreach (int next in graph[node])
        {
            if (!suspicious[next])
                DFS(next, graph, suspicious);
        }
    }

    private void DFS2(int node, List<int>[] graph, bool[] suspicious, bool[] visited)
    {
        visited[node] = true;

        foreach (int next in graph[node])
        {
            if (!visited[next])
            {
                suspicious[next] = false;
                DFS2(next, graph, suspicious, visited);
            }
        }
    }
}
