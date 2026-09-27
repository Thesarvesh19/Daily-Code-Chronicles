class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                string temp;

                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // Push reversed substring back
                for (char c : temp) {
                    st.push(c);
                }
            } 
            else {
                st.push(ch);
            }
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
