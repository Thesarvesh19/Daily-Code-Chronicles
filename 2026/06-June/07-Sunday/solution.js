var createBinaryTree = function(descriptions) {
    const nodes = new Map();
    const children = new Set();

    for (const [p, c, left] of descriptions) {
        if (!nodes.has(p))
            nodes.set(p, new TreeNode(p));

        if (!nodes.has(c))
            nodes.set(c, new TreeNode(c));

        if (left)
            nodes.get(p).left = nodes.get(c);
        else
            nodes.get(p).right = nodes.get(c);

        children.add(c);
    }

    for (const [p] of descriptions) {
        if (!children.has(p))
            return nodes.get(p);
    }

    return null;
};
