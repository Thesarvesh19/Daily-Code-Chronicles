class Solution {

    data class PairResult(
        val count: Long,
        val waviness: Long
    )

    private lateinit var s: String
    private val memo = HashMap<String, PairResult>()

    private fun dfs(
        pos: Int,
        prev: Int,
        prev2: Int,
        lead: Boolean,
        tight: Boolean
    ): PairResult {

        if (pos == s.length) {
            return PairResult(1L, 0L)
        }

        val key = "$pos|$prev|$prev2|$lead"

        if (!tight && memo.containsKey(key)) {
            return memo[key]!!
        }

        val limit =
            if (tight) s[pos] - '0'
            else 9

        var cnt = 0L
        var wav = 0L

        for (d in 0..limit) {

            val ntight = tight && d == limit
            val nlead = lead && d == 0

            val res = dfs(
                pos + 1,
                if (nlead) -1 else d,
                prev,
                nlead,
                ntight
            )

            cnt += res.count

            if (!lead &&
                prev2 != -1 &&
                (
                    (prev2 < prev && prev > d) ||
                    (prev2 > prev && prev < d)
                )
            ) {
                wav += res.count
            }

            wav += res.waviness
        }

        val ans = PairResult(cnt, wav)

        if (!tight) {
            memo[key] = ans
        }

        return ans
    }

    private fun solve(x: Long): Long {

        if (x <= 0L) return 0L

        s = x.toString()
        memo.clear()

        return dfs(
            0,
            -1,
            -1,
            true,
            true
        ).waviness
    }

    fun totalWaviness(
        num1: Long,
        num2: Long
    ): Long {

        return solve(num2) - solve(num1 - 1)
    }
}
