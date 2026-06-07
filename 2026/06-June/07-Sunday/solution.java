class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> map = new HashMap<>();
        Set<Integer> children = new HashSet<>();

        for (int[] d : descriptions) {
            int p = d[0];
            int c = d[1];
            int left = d[2];

            map.putIfAbsent(p, new TreeNode(p));
            map.putIfAbsent(c, new TreeNode(c));

            if (left == 1)
                map.get(p).left = map.get(c);
            else
                map.get(p).right = map.get(c);

            children.add(c);
        }

        for (int[] d : descriptions) {
            if (!children.contains(d[0]))
                return map.get(d[0]);
        }

        return null;
    }
}
