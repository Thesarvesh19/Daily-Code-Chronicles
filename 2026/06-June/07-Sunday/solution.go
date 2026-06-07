func createBinaryTree(descriptions [][]int) *TreeNode {
    nodes := map[int]*TreeNode{}
    children := map[int]bool{}

    for _, d := range descriptions {
        p, c, left := d[0], d[1], d[2]

        if nodes[p] == nil {
            nodes[p] = &TreeNode{Val: p}
        }

        if nodes[c] == nil {
            nodes[c] = &TreeNode{Val: c}
        }

        if left == 1 {
            nodes[p].Left = nodes[c]
        } else {
            nodes[p].Right = nodes[c]
        }

        children[c] = true
    }

    for _, d := range descriptions {
        if !children[d[0]] {
            return nodes[d[0]]
        }
    }

    return nil
}
