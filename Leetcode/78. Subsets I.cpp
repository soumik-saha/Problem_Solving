class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> subset;

        generateSubsets(0, nums, subset, result);

        vector<vector<int>> ans(result.begin(), result.end());

        return ans;
    }
    void generateSubsets(int i, vector<int>& nums, vector<int>& subset, set<vector<int>>& result) {
        result.insert(subset);

        for(int ind=i; ind<nums.size(); ind++) {
            subset.push_back(nums[ind]);
            generateSubsets(ind+1, nums, subset, result);
            subset.pop_back();
        }
    }
};
