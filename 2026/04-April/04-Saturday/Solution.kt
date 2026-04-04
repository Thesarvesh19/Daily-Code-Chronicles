//update
class Solution {
    fun decodeCiphertext(encodedText: String, rows: Int): String {
        if (rows == 1) return encodedText

        val n = encodedText.length
        val cols = n / rows

        val matrix = Array(rows) { CharArray(cols) }
        var idx = 0

        for (i in 0 until rows) {
            for (j in 0 until cols) {
                matrix[i][j] = encodedText[idx++]
            }
        }

        val res = StringBuilder()

        for (start in 0 until cols) {
            var i = 0
            var j = start
            while (i < rows && j < cols) {
                res.append(matrix[i][j])
                i++
                j++
            }
        }

        return res.toString().trimEnd()
    }
}
