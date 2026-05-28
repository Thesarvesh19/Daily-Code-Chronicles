class TrieNode {
    constructor() {
        this.children = {};
        this.idx = -1;
        this.length = Infinity;
    }
}

var stringIndices = function(wordsContainer, wordsQuery) {

    const root = new TrieNode();

    function update(node, idx, len) {
        if (len < node.length) {
            node.length = len;
            node.idx = idx;
        }
    }

    for (let i = 0; i < wordsContainer.length; i++) {
        let word = wordsContainer[i];

        let node = root;
        update(node, i, word.length);

        for (let j = word.length - 1; j >= 0; j--) {
            let ch = word[j];

            if (!node.children[ch]) {
                node.children[ch] = new TrieNode();
            }

            node = node.children[ch];
            update(node, i, word.length);
        }
    }

    let ans = [];

    for (let word of wordsQuery) {
        let node = root;

        for (let j = word.length - 1; j >= 0; j--) {
            let ch = word[j];

            if (!node.children[ch]) break;

            node = node.children[ch];
        }

        ans.push(node.idx);
    }

    return ans;
};
