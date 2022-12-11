class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>mp;
       for(auto i: nums){
           mp[(i%k+k)%k]++;
       }
       if(mp[0]%2==1)return 0;
       for(int i=1;i<k;i++){
           if(mp[i]!=mp[k-i])return 0;
       }
       return 1;
    }
};
