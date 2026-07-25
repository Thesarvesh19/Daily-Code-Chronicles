class Solution {
    fun maxProduct(n: Int): Int {
        var num = n
        var largest = 0
        var second = 0

        while (num > 0) {
            val digit = num % 10
            num /= 10

            if (digit >= largest) {
                second = largest
                largest = digit
            } else if (digit > second) {
                second = digit
            }
        }

        return largest * second
    }
}
