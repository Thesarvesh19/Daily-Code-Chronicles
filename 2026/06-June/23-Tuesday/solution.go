func zigZagArrays(n int, l int, r int) int {
    MOD := 1000000007
    r -= l
    dp := make([]int, r+1)
    for i := range dp {
        dp[i] = 1
    }
    
    for i := 1; i < n; i++ {
        pre := 0
        if i % 2 == 1 { // Up
            for v := 0; v <= r; v++ {
                pre2 := (pre + dp[v]) % MOD
                dp[v] = pre
                pre = pre2
            }
        } else { // Down
            for v := r; v >= 0; v-- {
                pre2 := (pre + dp[v]) % MOD
                dp[v] = pre
                pre = pre2
            }
        }
    }
    
    res := 0
    for _, v := range dp {
        res = (res + v) % MOD
    }
    return (res * 2) % MOD
}
