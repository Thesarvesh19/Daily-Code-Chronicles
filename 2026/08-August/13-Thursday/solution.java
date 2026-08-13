class Solution {

    // Node:
    // leftChar, rightChar, prefix, suffix, best, length
    static class Node {
        char leftChar;
        char rightChar;
        int prefix;
        int suffix;
        int best;
        int length;

        Node(char ch) {
            leftChar = ch;
            rightChar = ch;
            prefix = 1;
            suffix = 1;
            best = 1;
            length = 1;
        }
    }

    Node[] tree;

    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int n = s.length();

        tree = new Node[4 * n];

        build(s, 1, 0, n - 1);

        int[] answer = new int[queryIndices.length];

        for (int i = 0; i < queryIndices.length; i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters.charAt(i)
            );

            answer[i] = tree[1].best;
        }

        return answer;
    }

    private void build(String s, int node, int left, int right) {
        if (left == right) {
            tree[node] = new Node(s.charAt(left));
            return;
        }

        int mid = left + (right - left) / 2;

        build(s, node * 2, left, mid);
        build(s, node * 2 + 1, mid + 1, right);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    private void update(
        int node,
        int left,
        int right,
        int index,
        char ch
    ) {
        if (left == right) {
            tree[node] = new Node(ch);
            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid) {
            update(node * 2, left, mid, index, ch);
        } else {
            update(node * 2 + 1, mid + 1, right, index, ch);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    private Node merge(Node a, Node b) {
        Node res = new Node(a.leftChar);

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.length = a.length + b.length;

        // Initially take the best from either side
        res.best = Math.max(a.best, b.best);

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        // Characters at the boundary are equal
        if (a.rightChar == b.leftChar) {

            // Combine suffix of left segment
            // with prefix of right segment
            res.best = Math.max(
                res.best,
                a.suffix + b.prefix
            );

            // If the entire left segment is one character
            if (a.prefix == a.length) {
                res.prefix = a.length + b.prefix;
            }

            // If the entire right segment is one character
            if (b.suffix == b.length) {
                res.suffix = b.length + a.suffix;
            }
        }

        return res;
    }
}
