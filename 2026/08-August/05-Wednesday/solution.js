/**
 * @param {number} n
 * @param {number} k
 * @param {number[][]} invocations
 * @return {number[]}
 */
var remainingMethods = function (n, k, invocations) {
    const graph = Array.from({ length: n }, () => []);
    const undirected = Array.from({ length: n }, () => []);

    for (const [u, v] of invocations) {
        graph[u].push(v);
        undirected[u].push(v);
        undirected[v].push(u);
    }

    const suspicious = new Array(n).fill(false);

    const dfs = (u) => {
        suspicious[u] = true;
        for (const v of graph[u]) {
            if (!suspicious[v]) dfs(v);
        }
    };

    dfs(k);

    const visited = new Array(n).fill(false);

    const dfs2 = (u) => {
        visited[u] = true;
        for (const v of undirected[u]) {
            if (!visited[v]) {
                suspicious[v] = false;
                dfs2(v);
            }
        }
    };

    for (let i = 0; i < n; i++) {
        if (!suspicious[i] && !visited[i]) {
            dfs2(i);
        }
    }

    const ans = [];
    for (let i = 0; i < n; i++) {
        if (!suspicious[i]) ans.push(i);
    }

    return ans;
};
