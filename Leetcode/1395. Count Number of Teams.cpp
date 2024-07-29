class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            int leftSmaller = 0, leftGreater = 0;
            int rightSmaller = 0, rightGreater = 0;

            for(int j=i-1; j>=0; j--) {
                leftSmaller += (rating[j]<rating[i]) ? 1 : 0;
                leftGreater += (rating[j]>rating[i]) ? 1 : 0;
            }

            for(int j=i+1; j<n; j++) {
                rightSmaller += (rating[j]<rating[i]) ? 1 : 0;
                rightGreater += (rating[j]>rating[i]) ? 1 : 0;
            }

            ans += leftSmaller * rightGreater;
            ans += leftGreater * rightSmaller;
        }

        return ans;
    }
};
