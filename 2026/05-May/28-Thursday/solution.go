type TrieNode struct {
	children map[byte]*TrieNode
	idx      int
	length   int
}

func newTrieNode() *TrieNode {
	return &TrieNode{
		children: make(map[byte]*TrieNode),
		idx:      -1,
		length:   int(^uint(0) >> 1),
	}
}

func update(node *TrieNode, idx int, length int) {
	if length < node.length {
		node.length = length
		node.idx = idx
	}
}

func stringIndices(wordsContainer []string, wordsQuery []string) []int {

	root := newTrieNode()

	for i, word := range wordsContainer {

		node := root
		update(node, i, len(word))

		for j := len(word) - 1; j >= 0; j-- {
			ch := word[j]

			if _, ok := node.children[ch]; !ok {
				node.children[ch] = newTrieNode()
			}

			node = node.children[ch]
			update(node, i, len(word))
		}
	}

	ans := []int{}

	for _, word := range wordsQuery {

		node := root

		for j := len(word) - 1; j >= 0; j-- {
			ch := word[j]

			if _, ok := node.children[ch]; !ok {
				break
			}

			node = node.children[ch]
		}

		ans = append(ans, node.idx)
	}

	return ans
}
