class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, unordered_set<vector<int>>> mp;
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(nums[i]==nums[j])    continue;
                int mul = nums[i] * nums[j];
                mp[mul].insert({nums[i], nums[j]});
            }
        }

        return ans;
    }
};
