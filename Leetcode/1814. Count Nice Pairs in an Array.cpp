class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9+7;
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> rev(n, 0);
        vector<int> temp = nums;

        for(int i=0; i<n; i++) {
            while(temp[i]>0) {
                rev[i] = (rev[i]*10) + (temp[i]%10);
                temp[i] /= 10;
            }
        }

        vector<int> arr;
        for(int i=0; i<n; i++) {
            arr.push_back(nums[i]-rev[i]);
        }

        long long ans = 0;
        for(auto num : arr) {
            ans = (ans+mp[num])%MOD;
            mp[num]++;
        }

        return ans;
    }
};
