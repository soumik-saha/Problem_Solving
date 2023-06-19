class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,x=0;
        for(int i=0; i<gain.size(); i++) {
            x+=gain[i];
            ans=max(ans,x);
        }
        return ans;
    }
};
