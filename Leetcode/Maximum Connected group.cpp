class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        int n = s.size();

        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') {
                st.push(i);
            }
            else if(s[i]==')') {
                int start = st.top();
                st.pop();
                reverse(s.begin()+start+1, s.begin()+i);
            }
        }

        for(char c:s) {
            if(c=='(' || c==')')    continue;
            res.push_back(c);
        }

        return res;
    }
};
