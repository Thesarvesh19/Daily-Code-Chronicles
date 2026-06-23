/**
 * @param {number} n
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var zigZagArrays = function(n, l, r) {
    const MOD = 1000000007;
    r -= l;
    let dp = new Array(r + 1).fill(1);
    
    for (let i = 1; i < n; i++) {
        let pre = 0, pre2;
        if (i % 2 === 1) { // Up
            for (let v = 0; v <= r; v++) {
                pre2 = (pre + dp[v]) % MOD;
                dp[v] = pre;
                pre = pre2;
            }
        } else { // Down
            for (let v = r; v >= 0; v--) {
                pre2 = (pre + dp[v]) % MOD;
                dp[v] = pre;
                pre = pre2;
            }
        }
    }
    
    let res = 0;
    for (let i = 0; i <= r; i++) {
        res = (res + dp[i]) % MOD;
    }
    
    return (res * 2) % MOD;
};
