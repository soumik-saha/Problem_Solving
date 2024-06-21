class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(grumpy[i]==0) {
                ans += customers[i];
            }
        }
        int withoutConflict = ans;
        for(int i=0; i<n-minutes+1; i++) {
            int add = 0;
            for(int j=i; j<n && j<i+minutes; j++) {
                add += (grumpy[j] == 1) ? customers[j] : 0;
            }
            ans = max(ans, withoutConflict + add);
        }
        return ans;
    }
};
