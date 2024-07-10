class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string log:logs) {
            if(log=="../") {
                if(ans>0)
                    ans--;
            }
            else if(log=="./")
                continue;
            else
                ans++;
        }
        return ans;
    }
};
