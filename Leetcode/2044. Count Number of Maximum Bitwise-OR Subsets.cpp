class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxOr = -1;
        solve(0, nums, mp, maxOr, 0);
        return mp[maxOr];
    }
    void solve(int i, vector<int>& nums, unordered_map<int, int>& mp, int& maxOr, int currOr) {
        if(i>=nums.size()) {
            mp[currOr]++;
            maxOr = max(maxOr, currOr);
            return;
        }

        solve(i+1, nums, mp, maxOr, currOr | nums[i]);
        solve(i+1, nums, mp, maxOr, currOr);
    }
};
