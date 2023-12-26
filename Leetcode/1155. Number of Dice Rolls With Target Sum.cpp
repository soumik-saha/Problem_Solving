#define ll long long
class Solution {
public:
    const ll MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(n+1, vector<ll>(target+1, -1));
        return solve(0, n, k, target, dp);
    }
    ll solve(ll i, ll n, ll k, ll target, vector<vector<ll>>& dp) {
        if(i>=n) {
            if(target==0)
                return 1;
            return 0;
        }
        if(target<=0) {
            return 0;
        }
        if(dp[i][target]!=-1) {
            return dp[i][target];
        }
        ll sum = 0;
        for(ll ind=1; ind<=k; ind++) {
            sum = (sum + solve(i+1, n, k, target-ind, dp)) % MOD;
        }

        return dp[i][target] = sum%MOD;
    }
};
