class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> vals = arr;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < vals.size(); i++)
            rank[vals[i]] = i + 1;

        vector<int> ans;
        ans.reserve(arr.size());

        for (int x : arr)
            ans.push_back(rank[x]);

        return ans;
    }
};
