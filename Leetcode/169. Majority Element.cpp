class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int maxval = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums.at(i)]++;
            maxval = max(maxval, mp[nums.at(i)]);
        }
        for(auto it: mp){
            if(it.second==maxval)
                return it.first;
        }
        return -1;
    }
};
