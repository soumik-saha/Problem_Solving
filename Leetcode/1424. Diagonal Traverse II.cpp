class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=0; j<nums[i].size(); j++) {
                int diag = i + j;
                mp[diag].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        int curr = 0;

        while(mp.find(curr)!=mp.end()) {
            for(auto num : mp[curr]) {
                ans.push_back(num);
            }
            curr++;
        }

        return ans;
    }
};
