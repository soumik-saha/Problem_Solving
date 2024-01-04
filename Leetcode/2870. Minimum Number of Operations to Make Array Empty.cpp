class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for(int it:nums){
            mp[it]++;
        }

        int res = 0;
        
        for(auto it : mp) {
            int x = it.second;
            if(x==1)
                return -1;
            res+=x/3;
            if(x%3)
                res++;
        }
        return res;
    }
};
