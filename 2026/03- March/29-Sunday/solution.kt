class Solution {
    fun canBeEqual(s1: String, s2: String): Boolean {
        val s1Even = charArrayOf(s1[0], s1[2]).sortedArray()
        val s1Odd  = charArrayOf(s1[1], s1[3]).sortedArray()
        
        val s2Even = charArrayOf(s2[0], s2[2]).sortedArray()
        val s2Odd  = charArrayOf(s2[1], s2[3]).sortedArray()
        
        return s1Even.contentEquals(s2Even) && s1Odd.contentEquals(s2Odd)
    }
}
//updated code
