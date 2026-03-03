class Solution {
    fun findKthBit(n: Int, k: Int): Char {
        if (n == 1) return '0'

        val length = (1 shl n) - 1
        val mid = (length / 2) + 1

        return when { 
            k == mid -> '1'
            k < mid -> findKthBit(n - 1, k)
            else -> {
                val mirror = length - k + 1
                val bit = findKthBit(n - 1, mirror)
                if (bit == '0') '1' else '0'
            }
        }
    }
}
