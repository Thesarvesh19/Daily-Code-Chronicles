class Solution {

    private fun removeInvalid(
        s: String,
        ans: MutableList<String>,
        lastI: Int,
        lastJ: Int,
        open: Char,
        close: Char
    ) {
        var balance = 0

        for (i in lastI until s.length) {

            when (s[i]) {
                open -> balance++
                close -> balance--
            }

            // String is still valid
            if (balance >= 0) continue

            // Extra closing parenthesis found
            for (j in lastJ..i) {

                // Avoid duplicate removals
                if (s[j] == close &&
                    (j == lastJ || s[j - 1] != close)
                ) {
                    val next = s.removeRange(j, j + 1)

                    removeInvalid(
                        next,
                        ans,
                        i,
                        j,
                        open,
                        close
                    )
                }
            }

            // Only fix the first invalid position
            return
        }

        // No extra closing parenthesis remains.

        // Reverse and solve the opposite problem.
        val reversed = s.reversed()

        if (open == '(') {

            removeInvalid(
                reversed,
                ans,
                0,
                0,
                ')',
                '('
            )

        } else {

            // Completely valid string
            ans.add(reversed)
        }
    }

    fun removeInvalidParentheses(s: String): List<String> {

        val ans = mutableListOf<String>()

        removeInvalid(
            s,
            ans,
            0,
            0,
            '(',
            ')'
        )

        return ans
    }
}
