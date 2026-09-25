#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<string> ans;

    void dfs(string exp) {
        // No braces left
        if (exp.find('}') == string::npos) {
            ans.insert(exp);
            return;
        }

        // Find first closing brace
        int right = exp.find('}');

        // Find its matching opening brace
        int left = exp.rfind('{', right);

        // Extract prefix and suffix
        string prefix = exp.substr(0, left);
        string suffix = exp.substr(right + 1);

        // Extract content inside braces
        string inside = exp.substr(left + 1, right - left - 1);

        // Split by commas
        string part;
        stringstream ss(inside);

        while (getline(ss, part, ',')) {
            dfs(prefix + part + suffix);
        }
    }

    vector<string> braceExpansionII(string expression) {
        dfs(expression);

        return vector<string>(ans.begin(), ans.end());
    }
};
