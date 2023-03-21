class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        map<long long,long long>mp;
        for(int i=0; i<nums.size(); i++) {
            long long cnt0 = 0;
            if(nums[i]==0) {
                cnt0 = 1;
                for(int k=i+1; k<nums.size(); k++) {
                    if(nums[k]==0)
                        cnt0++;
                    else
                        break;
                }
                if(mp[cnt0]>=0)
                    mp[cnt0]++;
                else
                    mp[cnt0]=1;
                
                i+=cnt0;
            }
        }
        long long res = 0;
        for(auto x: mp){
            long long k = factsum(x.first);
            res+=(k*x.second);
        }
        return res;
    }
    long long factsum(long long n) {
        if(n==1)
            return 1;
        return n+factsum(n-1);
    }
};
