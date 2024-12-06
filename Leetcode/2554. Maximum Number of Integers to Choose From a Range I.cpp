class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int sum = 0;
        int i = 1;
        int ans = 0;
        while(i<=n && sum<maxSum) {
            if(st.find(i)==st.end()) {
                sum += i;
                if(sum>maxSum) {
                    return ans;
                }
                ans++;
            }
            i++;
        }
        return ans;
    }
};
