class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        st.push({temperatures[n-1], n-1});

        for(int i=n-2; i>=0; i--) {
            while(!st.empty()) {
                if(temperatures[i]<st.top().first) {
                    ans[i] = st.top().second - i;
                    break;
                }
                else {
                    st.pop();
                }
            }
            if(st.empty() || st.top().first>temperatures[i])
                st.push({temperatures[i], i});
        }
        return ans;
    }
};
