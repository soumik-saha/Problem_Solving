class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        for(int i=0; i<nums.size(); i++) {
            int x=nums[i];
            while(i+1<nums.size() && nums[i]+1==nums[i+1]) {
                i++;
            }
            if(x != nums[i]) {
                string s = to_string(x) + "->" + to_string(nums[i]);
                res.push_back(s);
            }
            else {
                res.push_back(to_string(x));
            }
        }
        return res;
    }
};
