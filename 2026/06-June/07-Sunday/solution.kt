class Solution {
    fun createBinaryTree(descriptions: Array<IntArray>): TreeNode? {

        val map = HashMap<Int, TreeNode>()
        val children = HashSet<Int>()

        for (d in descriptions) {
            val p = d[0]
            val c = d[1]
            val left = d[2]

            map.putIfAbsent(p, TreeNode(p))
            map.putIfAbsent(c, TreeNode(c))

            if (left == 1)
                map[p]!!.left = map[c]
            else
                map[p]!!.right = map[c]

            children.add(c)
        }

        for (d in descriptions) {
            if (!children.contains(d[0]))
                return map[d[0]]
        }

        return null
    }
}
