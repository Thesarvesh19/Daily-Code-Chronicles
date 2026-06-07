class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childs;

        for (auto &d : descriptions) {
            int p = d[0];
            int c = d[1];
            int left = d[2];

            if (!mp.count(p))
                mp[p] = new TreeNode(p);

            if (!mp.count(c))
                mp[c] = new TreeNode(c);

            if (left)
                mp[p]->left = mp[c];
            else
                mp[p]->right = mp[c];

            childs.insert(c);
        }

        for (auto &d : descriptions) {
            if (!childs.count(d[0]))
                return mp[d[0]];
        }

        return nullptr;
    }
};
