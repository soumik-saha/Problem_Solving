class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp[nums[i]]>nums.size()/3)
            {
                ans.push_back(nums[i]);
                mp[nums[i]]=0;
            }
        }
        
        if(ans.empty())
        {
            ans.push_back(-1);
        }
        
        return ans;
    }
};
