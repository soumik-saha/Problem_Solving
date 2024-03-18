class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            if(ans.empty()) {
                ans.push_back(points[i][1]);
            } 
            else if(ans.back()>=points[i][0]) {
                ans.back() = min(ans.back(), points[i][1]);
            }
            else {
                ans.push_back(points[i][1]);
            }
        }
        
        return ans.size();
    }
};
