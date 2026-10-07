class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int index, int leftRem, int rightRem,
               int leftCount, int rightCount, string current) {

        // Reached the end
        if (index == s.size()) {
            if (leftRem == 0 && rightRem == 0 &&
                leftCount == rightCount) {
                ans.insert(current);
            }
            return;
        }

        char ch = s[index];

        // Option 1: Remove current parenthesis
        if (ch == '(' && leftRem > 0) {
            solve(s, index + 1, leftRem - 1, rightRem,
                  leftCount, rightCount, current);
        }

        if (ch == ')' && rightRem > 0) {
            solve(s, index + 1, leftRem, rightRem - 1,
                  leftCount, rightCount, current);
        }

        // Option 2: Keep current character
        current += ch;

        if (ch != '(' && ch != ')') {
            solve(s, index + 1, leftRem, rightRem,
                  leftCount, rightCount, current);
        }
        else if (ch == '(') {
            solve(s, index + 1, leftRem, rightRem,
                  leftCount + 1, rightCount, current);
        }
        else if (ch == ')' && rightCount < leftCount) {
            solve(s, index + 1, leftRem, rightRem,
                  leftCount, rightCount + 1, current);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum removals required
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {
                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        solve(s, 0, leftRem, rightRem, 0, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
