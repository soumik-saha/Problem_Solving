class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()<2) return stoi(tokens[0]);

        int ans = 0;
        stack<string> st;

        st.push(tokens[0]);
        st.push(tokens[1]);

        int i = 2;
        while(!st.empty() && i<tokens.size()) {
            if((tokens[i][0]!='-' && (tokens[i][0]-'0'>=0 && tokens[i][0]-'0'<=9)) || (tokens[i][0]=='-' && tokens[i].size()>=2 && (tokens[i][1]-'0'>=0 && tokens[i][1]-'0'<=9))) {
                st.push(tokens[i]);
            }
            else {
                char op = tokens[i][0];
                int b = stoi(st.top()), a = 0;
                st.pop();
                if(!st.empty()) {
                    a = stoi(st.top());
                    st.pop();
                }
                switch(op) {
                    case '+':
                        ans = (a+b);
                        break;
                    case '-':
                        ans = (a-b);
                        break;
                    case '*':
                        ans = (a*b);
                        break;
                    case '/':
                        if(b!=0)
                            ans = (a/b);
                        break;
                }
                st.push(to_string(ans));
            }
            i++;
        }
        return ans;
    }
};
