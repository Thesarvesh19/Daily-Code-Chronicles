public class Solution {
    public TreeNode CreateBinaryTree(int[][] descriptions) {

        Dictionary<int, TreeNode> map =
            new Dictionary<int, TreeNode>();

        HashSet<int> children = new HashSet<int>();

        foreach (var d in descriptions) {
            int p = d[0];
            int c = d[1];
            int left = d[2];

            if (!map.ContainsKey(p))
                map[p] = new TreeNode(p);

            if (!map.ContainsKey(c))
                map[c] = new TreeNode(c);

            if (left == 1)
                map[p].left = map[c];
            else
                map[p].right = map[c];

            children.Add(c);
        }

        foreach (var d in descriptions) {
            if (!children.Contains(d[0]))
                return map[d[0]];
        }

        return null;
    }
}
