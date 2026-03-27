class Solution {
    fun areSimilar(mat: Array<IntArray>, k: Int): Boolean {
        val m = mat.size
        val n = mat[0].size

        val shift = k % n

        if (shift == 0) return true

        for (i in 0 until m) {
            val row = mat[i]
            val shifted = IntArray(n)

            if (i % 2 == 0) {
                // left shift
                for (j in 0 until n) {
                    shifted[j] = row[(j + shift) % n]
                }
            } else {
                // right shift
                for (j in 0 until n) {
                    shifted[j] = row[(j - shift + n) % n]
                }
            }

            for (j in 0 until n) {
                if (shifted[j] != row[j]) {
                    return false
                }
            }
        }

        return true
    }
}
