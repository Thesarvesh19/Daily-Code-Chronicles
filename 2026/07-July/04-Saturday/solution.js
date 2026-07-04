var minScore = function(n, roads) {
    const graph = Array.from({ length: n + 1 }, () => []);

    for (const [u, v, d] of roads) {
        graph[u].push([v, d]);
        graph[v].push([u, d]);
    }

    const visited = Array(n + 1).fill(false);
    const queue = [1];
    visited[1] = true;

    let ans = Infinity;

    while (queue.length) {
        const node = queue.shift();

        for (const [next, dist] of graph[node]) {
            ans = Math.min(ans, dist);

            if (!visited[next]) {
                visited[next] = true;
                queue.push(next);
            }
        }
    }

    return ans;
};
