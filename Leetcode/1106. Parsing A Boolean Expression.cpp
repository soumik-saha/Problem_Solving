class Solution {
public:
    bool parseBoolExpr(std::string exp) {
        stack<char> st;
        stack<char> op;

        for (char ch : exp) {
            if (ch == '&' || ch == '|' || ch == '!') {
                op.push(ch);
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                char currOp = op.top();
                op.pop();

                std::vector<char> c;

                while (!st.empty() && st.top() != '(') {
                    c.push_back(st.top());
                    st.pop();
                }
                st.pop(); 

                char result = (currOp == '!') ? (c.front() == 't' ? 'f' : 't') : c.front();
                
                for (size_t k = 1; k < c.size(); ++k) {
                    char x2 = c[k];
                    if (currOp == '&') {
                        result = (result == 't' && x2 == 't') ? 't' : 'f';
                    } else if (currOp == '|') {
                        result = (result == 't' || x2 == 't') ? 't' : 'f';
                    }
                }
                
                st.push(result);
            } else {
                if(ch==',') continue;
                st.push(ch); 
            }
        }

        return st.top() == 't';
    }
};
