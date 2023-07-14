class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int ans = 0;
        unordered_map<int, int> dp;
        for(int i=0; i<arr.size(); i++) {
            if(dp[arr[i]-diff]>0)
                dp[arr[i]] = dp[arr[i]-diff]+1;
            else
                dp[arr[i]] = 1;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};
