class Solution {
    fun closestTarget(words: Array<String>, target: String, startIndex: Int): Int {
        val n = words.size
        var ans = Int.MAX_VALUE
        
        for (i in 0 until n) {
            if (words[i] == target) {
                val d = Math.abs(i - startIndex)
                ans = minOf(ans, minOf(d, n - d))
            }
        }
        
        return if (ans == Int.MAX_VALUE) -1 else ans
    }
}
