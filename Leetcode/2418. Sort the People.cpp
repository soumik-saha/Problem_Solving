class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int, vector<string>> mp;
        int n = heights.size();

        for(int i=0; i<n; i++) {
            mp[heights[i]].push_back(names[i]);
        }
        for(auto &[key, val] : mp) {
            for(string s:val)
                ans.push_back(s);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
