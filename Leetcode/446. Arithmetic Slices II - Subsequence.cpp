#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        
        vector<unordered_map<ll, int>> dp(n);
        for(ll i=1; i<n; i++) {
            for(ll j=0; j<i; j++) {
                ll diff = (ll) nums[i]-nums[j];
                
                dp[i][diff] += dp[j][diff]+1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};
