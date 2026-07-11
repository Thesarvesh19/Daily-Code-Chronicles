var countCompleteComponents = function(n, edges) {
    const graph = Array.from({ length: n }, () => []);

    for (const [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
    }

    const visited = new Array(n).fill(false);
    let answer = 0;

    for (let i = 0; i < n; i++) {
        if (visited[i]) continue;

        const stack = [i];
        visited[i] = true;

        let nodes = 0;
        let degreeSum = 0;

        while (stack.length) {
            const cur = stack.pop();
            nodes++;
            degreeSum += graph[cur].length;

            for (const nxt of graph[cur]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    stack.push(nxt);
                }
            }
        }

        if (degreeSum / 2 === (nodes * (nodes - 1)) / 2)
            answer++;
    }

    return answer;
};
