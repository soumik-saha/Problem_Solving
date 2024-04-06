class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int open = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            }
            if (c == ')') {
                open--;
                if (open < 0) {
                    open = 0;
                    continue;
                }
            }
            st.push(c);
        }

        string ans;

        while (open > 0 && !st.empty()) {
            if (st.top() == '(') {
                open--;
                st.pop();
            } else {
                ans += st.top();
                st.pop();
            }
        }

        while (open == 0 && !st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
