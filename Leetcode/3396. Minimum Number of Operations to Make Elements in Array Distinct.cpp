class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        while(nums.size()>0) {
            unordered_set<int> st(nums.begin(), nums.end());
            if(st.size()==nums.size())  return ops;
            ops++;
            if(nums.size()>0)   nums.erase(nums.begin());
            if(nums.size()>0)   nums.erase(nums.begin());
            if(nums.size()>0)   nums.erase(nums.begin());
        }
        return ops;
    }
};
