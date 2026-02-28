class Solution {
    fun concatenatedBinary(n: Int): Int {
        val MOD = 1_000_000_007
        var result = 0L
        var length = 0
        
        for (i in 1..n) {
           
            if ((i and (i - 1)) == 0) {
                length++
            }
            
          
            result = ((result shl length) + i) % MOD
        }
        
        return result.toInt()
    }
}
