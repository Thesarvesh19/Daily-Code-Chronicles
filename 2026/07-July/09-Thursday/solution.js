function pathExistenceQueries(n: number, nums: number[], maxDiff: number, queries: number[][]): boolean[] {
    const g = new Int32Array(n);
    let cnt = 0;
    
    for (let i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] > maxDiff) {
            cnt++;
        }
        g[i] = cnt;
    }
    
    return queries.map(q => g[q[0]] === g[q[1]]);
}
