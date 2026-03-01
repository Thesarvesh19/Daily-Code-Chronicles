class Solution {
    fun minPartitions(n: String): Int {
        var maxDigit = 0
         
        for (ch in n) {
            maxDigit = maxOf(maxDigit, ch - '0')
        }
        
        return maxDigit
    }
}
