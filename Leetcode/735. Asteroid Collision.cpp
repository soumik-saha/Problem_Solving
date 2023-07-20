class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i :  asteroids) {
            int flag = 1;
            while(!st.empty() && (st.top()>0 && i<0)) {
                if(abs(st.top()) < abs(i)) {
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(i)) {
                    st.pop();
                }
                flag = 0;
                break;
            }
            if(flag) {
                st.push(i);
            }
        }
        
        vector<int> rem(st.size());
        for(int i=rem.size()-1; i>=0; i--) {
            rem[i] = st.top();
            st.pop();
        }

        return rem;
    }
};
