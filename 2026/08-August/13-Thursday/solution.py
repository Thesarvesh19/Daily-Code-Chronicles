class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: list[int]) -> list[int]:
        n = len(s)

        # Each node:
        # [left_char, right_char, prefix, suffix, best]
        tree = [None] * (4 * n)

        def make_node(ch):
            return [ch, ch, 1, 1, 1]

        def merge(a, b):
            if a is None:
                return b
            if b is None:
                return a

            left = a[0]
            right = b[1]

            pref = a[2]
            suff = b[3]
            best = max(a[4], b[4])

            # Entire boundary has the same character
            if a[1] == b[0]:
                best = max(best, a[3] + b[2])

                if a[2] == a[3]:
                    pref = a[2] + b[2]

                if b[2] == b[3]:
                    suff = b[3] + a[3]

            return [left, right, pref, suff, best]

        def build(node, l, r):
            if l == r:
                tree[node] = make_node(s[l])
                return

            mid = (l + r) // 2
            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        def update(node, l, r, idx, ch):
            if l == r:
                tree[node] = make_node(ch)
                return

            mid = (l + r) // 2

            if idx <= mid:
                update(node * 2, l, mid, idx, ch)
            else:
                update(node * 2 + 1, mid + 1, r, idx, ch)

            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        build(1, 0, n - 1)

        ans = []

        for ch, idx in zip(queryCharacters, queryIndices):
            update(1, 0, n - 1, idx, ch)
            ans.append(tree[1][4])

        return ans
