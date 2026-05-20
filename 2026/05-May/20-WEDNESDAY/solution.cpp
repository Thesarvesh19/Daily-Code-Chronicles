class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        vector<int> count(n + 1, 0);

        int common = 0;

        for(int i = 0; i < n; i++) {
            if(++count[A[i]] == 2)
                common++;

            if(++count[B[i]] == 2)
                common++;

            ans.push_back(common);
        }

        return ans;
    }
};
