class Solution {

    class TrieNode {
        val children = HashMap<Char, TrieNode>()
        var idx = -1
        var length = Int.MAX_VALUE
    }

    fun stringIndices(wordsContainer: Array<String>,
                      wordsQuery: Array<String>): IntArray {

        val root = TrieNode()

        fun update(node: TrieNode, idx: Int, len: Int) {
            if (len < node.length) {
                node.length = len
                node.idx = idx
            }
        }

        for (i in wordsContainer.indices) {
            val word = wordsContainer[i]

            var node = root
            update(node, i, word.length)

            for (j in word.length - 1 downTo 0) {
                val ch = word[j]

                node.children.putIfAbsent(ch, TrieNode())
                node = node.children[ch]!!

                update(node, i, word.length)
            }
        }

        val ans = IntArray(wordsQuery.size)

        for (i in wordsQuery.indices) {
            val word = wordsQuery[i]

            var node = root

            for (j in word.length - 1 downTo 0) {
                val ch = word[j]

                if (!node.children.containsKey(ch))
                    break

                node = node.children[ch]!!
            }

            ans[i] = node.idx
        }

        return ans
    }
}
