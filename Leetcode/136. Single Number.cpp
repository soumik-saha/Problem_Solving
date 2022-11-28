class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i=i+1){
            mp[nums.at(i)]++;
        }
        for(auto it : mp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};
