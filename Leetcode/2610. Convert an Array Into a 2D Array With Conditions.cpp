class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int it : nums) {
            mp[it]++;
        }
        vector<vector<int>> res;
        int cnt = 0;
        while(cnt++ < nums.size()) {
            vector<int> row;
            for(auto& it : mp) {
                if(it.second>=1) {
                    row.push_back(it.first);
                    it.second--;
                }
            }
            if(row.empty())
                break;
            res.push_back(row);
        }
        return res;
    }
};
