class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sortedNums;
        
        for(int i=0; i<nums.size(); i++){
            sortedNums.emplace_back(pow(nums[i],2));
        }
        
        sort(sortedNums.begin(), sortedNums.end());
        
        return sortedNums;
    }
};
