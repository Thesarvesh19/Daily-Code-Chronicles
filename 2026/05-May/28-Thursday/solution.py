class TrieNode:
    def __init__(self):
        self.children = {}
        self.idx = -1
        self.length = float('inf')


class Solution:
    def stringIndices(self, wordsContainer, wordsQuery):
        root = TrieNode()

        def update(node, index, word):
            if len(word) < node.length:
                node.length = len(word)
                node.idx = index

        for i, word in enumerate(wordsContainer):
            node = root
            update(node, i, word)

            for ch in reversed(word):
                if ch not in node.children:
                    node.children[ch] = TrieNode()

                node = node.children[ch]
                update(node, i, word)

        ans = []

        for word in wordsQuery:
            node = root

            for ch in reversed(word):
                if ch not in node.children:
                    break
                node = node.children[ch]

            ans.append(node.idx)

        return ans
