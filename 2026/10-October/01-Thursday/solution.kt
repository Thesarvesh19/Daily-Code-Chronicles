
class Solution {
    fun isValid(s: String): Boolean {
        val stack = ArrayDeque<Char>()

        for (ch in s) {
            when (ch) {
                '(', '{', '[' -> stack.addLast(ch)

                ')' -> {
                    if (stack.isEmpty() || stack.removeLast() != '(') {
                        return false
                    }
                }

                '}' -> {
                    if (stack.isEmpty() || stack.removeLast() != '{') {
                        return false
                    }
                }

                ']' -> {
                    if (stack.isEmpty() || stack.removeLast() != '[') {
                        return false
                    }
                }
            }
        }

        return stack.isEmpty()
    }
}
