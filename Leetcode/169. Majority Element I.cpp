class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxCnt = 0, ans = 0;
        for(int it:nums){
            mp[it]++;
            if(mp[it]>maxCnt) {
                maxCnt = mp[it];
                ans = it;
            }
        }
        return ans;
    }
};
