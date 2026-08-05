import java.util.*;

class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        List<Integer>[] graph = new ArrayList[n];
        List<Integer>[] undirected = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            undirected[i] = new ArrayList<>();
        }

        for (int[] e : invocations) {
            int u = e[0];
            int v = e[1];
            graph[u].add(v);
            undirected[u].add(v);
            undirected[v].add(u);
        }

        boolean[] suspicious = new boolean[n];
        dfs(k, graph, suspicious);

        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !visited[i]) {
                dfs2(i, undirected, suspicious, visited);
            }
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.add(i);
            }
        }

        return ans;
    }

    private void dfs(int node, List<Integer>[] graph, boolean[] suspicious) {
        suspicious[node] = true;

        for (int nxt : graph[node]) {
            if (!suspicious[nxt]) {
                dfs(nxt, graph, suspicious);
            }
        }
    }

    private void dfs2(int node, List<Integer>[] graph,
                      boolean[] suspicious, boolean[] visited) {

        visited[node] = true;

        for (int nxt : graph[node]) {
            if (!visited[nxt]) {
                suspicious[nxt] = false;
                dfs2(nxt, graph, suspicious, visited);
            }
        }
    }
}
