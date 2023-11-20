class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> v(3, 0);
        int n = garbage.size(), cnt = 0;
        for(int i=n-1; i>=0; i--) {
            for(char j : garbage[i]) {
                if(j=='M') {
                    v[0] = max(v[0], i);
                }
                else if(j=='P') {
                    v[1] = max(v[1], i);
                }
                else {
                    v[2] = max(v[2], i);
                }
                cnt++;
            }
        }

        vector<int> prefSum(travel.size());
        prefSum[0] = travel[0];
        for(int i=1; i<n-1; i++) {
            prefSum[i] = prefSum[i-1] + travel[i];
        }

        for(int i=0; i<3; i++) {
            if(v[i]>0)
                cnt += prefSum[v[i]-1];
        }

        return cnt;
    }
};
