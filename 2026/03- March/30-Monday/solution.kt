class Solution {
    fun checkStrings(s1: String, s2: String): Boolean {
        val even = IntArray(26)
        val odd = IntArray(26)
 
        for (i in s1.indices) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++
                even[s2[i] - 'a']--
            } else {
                odd[s1[i] - 'a']++
                odd[s2[i] - 'a']--
            }
        }

        return even.all { it == 0 } && odd.all { it == 0 }
    }
}
