class Solution {

    function createBinaryTree($descriptions) {

        $nodes = [];
        $children = [];

        foreach ($descriptions as $d) {

            [$p, $c, $left] = $d;

            if (!isset($nodes[$p]))
                $nodes[$p] = new TreeNode($p);

            if (!isset($nodes[$c]))
                $nodes[$c] = new TreeNode($c);

            if ($left)
                $nodes[$p]->left = $nodes[$c];
            else
                $nodes[$p]->right = $nodes[$c];

            $children[$c] = true;
        }

        foreach ($descriptions as $d) {
            if (!isset($children[$d[0]]))
                return $nodes[$d[0]];
        }

        return null;
    }
}
