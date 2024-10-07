class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        stack<char> stk;

        for(int i=0; i<n; i++) {
            if(!stk.empty() && ((stk.top()=='A' && s[i]=='B') || (stk.top()=='C' && s[i]=='D'))) {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }

        return stk.size();
    }
};
