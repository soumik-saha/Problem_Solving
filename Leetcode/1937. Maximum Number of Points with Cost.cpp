class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<long long> prev(n);
        for(int j=0; j<n; j++) {
            prev[j] = points[0][j];
        }

        for(int i=1; i<m; i++) {
            vector<long long> leftMax(n), rightMax(n), current(n);

            leftMax[0] = prev[0];
            for(int j=1; j<n; j++) {
                leftMax[j] = max(leftMax[j-1]-1, prev[j]);
            }
            
            rightMax[n-1] = prev[n-1];
            for(int j=n-2; j>=0; j--) {
                rightMax[j] = max(rightMax[j+1]-1, prev[j]);
            }

            for(int j=0; j<n; j++) {
                current[j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }

            prev = current;
        }

        return *max_element(prev.begin(), prev.end());
    }
};
