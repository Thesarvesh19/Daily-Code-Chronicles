public class Solution
{
    public int MinScore(int n, int[][] roads)
    {
        List<(int, int)>[] graph = new List<(int, int)>[n + 1];

        for (int i = 0; i <= n; i++)
            graph[i] = new List<(int, int)>();

        foreach (var road in roads)
        {
            graph[road[0]].Add((road[1], road[2]));
            graph[road[1]].Add((road[0], road[2]));
        }

        bool[] visited = new bool[n + 1];
        Queue<int> queue = new Queue<int>();

        queue.Enqueue(1);
        visited[1] = true;

        int ans = int.MaxValue;

        while (queue.Count > 0)
        {
            int node = queue.Dequeue();

            foreach (var (next, dist) in graph[node])
            {
                ans = Math.Min(ans, dist);

                if (!visited[next])
                {
                    visited[next] = true;
                    queue.Enqueue(next);
                }
            }
        }

        return ans;
    }
}
