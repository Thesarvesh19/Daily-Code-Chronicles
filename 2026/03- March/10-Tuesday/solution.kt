class Solution {
    fun numberOfStableArrays(zero: Int, one: Int, limit: Int): Int {
        val MOD = 1_000_000_007

        val dp = Array(zero + 1) {
            Array(one + 1) {
                LongArray(2)
            }
        }

        for (i in 0..minOf(zero, limit)) {
            dp[i][0][0] = 1
        }

        for (j in 0..minOf(one, limit)) {
            dp[0][j][1] = 1
        }

        for (i in 1..zero) {
            for (j in 1..one) {

                var val0 = dp[i - 1][j][0] + dp[i - 1][j][1]
                if (i - limit - 1 >= 0) {
                    val0 -= dp[i - limit - 1][j][1]
                }
                dp[i][j][0] = ((val0 % MOD) + MOD) % MOD

                var val1 = dp[i][j - 1][0] + dp[i][j - 1][1]
                if (j - limit - 1 >= 0) {
                    val1 -= dp[i][j - limit - 1][0]
                }
                dp[i][j][1] = ((val1 % MOD) + MOD) % MOD
            }
        }

        return ((dp[zero][one][0] + dp[zero][one][1]) % MOD).toInt()
    }
}
