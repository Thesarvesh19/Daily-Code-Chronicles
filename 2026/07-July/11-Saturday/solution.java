import java.util.*;

class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();

        for (int[] e : edges) {
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
        }

        boolean[] visited = new boolean[n];
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            Stack<Integer> stack = new Stack<>();
            stack.push(i);
            visited[i] = true;

            int nodes = 0;
            int degreeSum = 0;

            while (!stack.isEmpty()) {
                int cur = stack.pop();
                nodes++;
                degreeSum += graph[cur].size();

                for (int next : graph[cur]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        stack.push(next);
                    }
                }
            }

            if (degreeSum / 2 == nodes * (nodes - 1) / 2)
                answer++;
        }

        return answer;
    }
}
