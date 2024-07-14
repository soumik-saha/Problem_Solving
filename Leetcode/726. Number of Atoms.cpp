class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        map<string, int> mp;
        stack<map<string, int>> st;
        st.push(mp);
        int i=0; 

        while(i<n) {
            if(formula[i]=='(') {
                map<string, int> mp2;
                st.push(mp2);
                i++;
            }
            else if(formula[i]==')') {
                i++;
                int num = 0;
                while(i<n && isdigit(formula[i])) {
                    num = num*10 + (formula[i++]-'0');
                }
                num = (num==0) ? 1:num;
                auto current = st.top();
                st.pop();
                for(auto &[ele, cnt]:current) {
                    st.top()[ele] += cnt * num;
                }
            }
            else {
                string ele = "";
                ele += formula[i++];
                while(i<n && islower(formula[i])) {
                    ele += formula[i++];
                }
                int num = 0;
                while(i<n && isdigit(formula[i])) {
                    num = num*10 + (formula[i++]-'0');
                }

                num = (num==0) ? 1:num;

                st.top()[ele] += num;
            }
        }

        string res = "";
        auto finalmp = st.top();
        for(auto &[ele, cnt]:finalmp) {
            res += ele + (cnt>1 ? to_string(cnt) : "");
        }

        return res;
    }
};
