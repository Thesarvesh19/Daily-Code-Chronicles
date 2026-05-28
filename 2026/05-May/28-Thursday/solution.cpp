class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int idx = -1;
    int length = INT_MAX;
};

class Solution {
public:

    void update(TrieNode* node, int idx, int len) {
        if (len < node->length) {
            node->length = len;
            node->idx = idx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        TrieNode* root = new TrieNode();

        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];

            TrieNode* node = root;
            update(node, i, word.size());

            for (int j = word.size() - 1; j >= 0; j--) {
                char ch = word[j];

                if (!node->children.count(ch))
                    node->children[ch] = new TrieNode();

                node = node->children[ch];
                update(node, i, word.size());
            }
        }

        vector<int> ans;

        for (string word : wordsQuery) {
            TrieNode* node = root;

            for (int j = word.size() - 1; j >= 0; j--) {
                char ch = word[j];

                if (!node->children.count(ch))
                    break;

                node = node->children[ch];
            }

            ans.push_back(node->idx);
        }

        return ans;
    }
};
