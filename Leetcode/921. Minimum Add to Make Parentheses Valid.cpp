class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char c:s) {
            if(c==')') {
                if(!stk.empty() && stk.top()=='(') {
                    stk.pop();
                }
                else {
                    stk.push(c);
                }
            }
            else {
                stk.push(c);
            }
        }
        return stk.size();
    }
};
