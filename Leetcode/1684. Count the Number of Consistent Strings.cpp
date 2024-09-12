class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_set<char> st(allowed.begin(), allowed.end());
        for(auto word:words) {
            bool flag = true;
            for(auto ch:word) {
                if(st.find(ch)==st.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag)    ans++;
        }
        return ans;
    }
};
