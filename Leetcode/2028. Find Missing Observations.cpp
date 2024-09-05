class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int remSum = (mean*(m+n)) - accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> ans;

        if(remSum<n || remSum>(n*6)) {
            return ans;
        }

        int each = remSum/n;
        ans.resize(n, each);
        int remainSum = remSum - (n*each);
        int i = 0;

        while(i<n && remainSum>0) {
            int ele;
            if(ans[i]+remainSum<=6) {
                ele = remainSum;
            }
            else {
                if(ans[i]==6) {
                    i++;
                    continue;
                }
                else {
                    ele = 6-ans[i];
                }
            }
            ans[i]+=ele;
            remainSum -= ele;
            i++;
        }

        return ans;
    }
};
