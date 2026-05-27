class Solution {
    fun numberOfSpecialChars(word: String): Int {

        val lower = mutableSetOf<Char>()
        val upper = mutableSetOf<Char>()

        for(ch in word){
            if(ch.isLowerCase())
                lower.add(ch)
            else
                upper.add(ch.lowercaseChar())
        }

        return lower.intersect(upper).size
    }
}
