class Solution {
public:
    bool dfs(vector<int>& arr, int idx) {
        if (idx < 0 || idx >= arr.size() || arr[idx] < 0)
            return false;

        if (arr[idx] == 0)
            return true;

        int jump = arr[idx];
        arr[idx] = -arr[idx];   // mark visited

        return dfs(arr, idx + jump) ||
               dfs(arr, idx - jump);
    }

    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
};
