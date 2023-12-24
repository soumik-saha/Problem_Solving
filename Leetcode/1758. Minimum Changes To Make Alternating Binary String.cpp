class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = 0;
        int cnt1=0, cnt0=0;
        for(int i=0; i<s.size(); i=i+1) {
            if(i%2==0) {
                if(s[i]=='1') {
                    cnt1++;
                } else {
                    cnt0++;
                }
            } else {
                if(s[i]=='0') {
                    cnt1++;
                } else {
                    cnt0++;
                }
            }
        }
        ans = min(cnt1, cnt0);

        return ans;
    }
};
