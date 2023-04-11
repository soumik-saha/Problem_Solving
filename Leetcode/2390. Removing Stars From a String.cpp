class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            st.push(s[i]);
            if(st.top()=='*'){
                st.pop();
                st.pop();
            }
        }

        string nstr;

        while(!st.empty()) {
            nstr.push_back(st.top());
            st.pop();
        }

        reverse(nstr.begin(), nstr.end());
        
        return nstr;
    }
};
