class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int ans = INT_MAX;
        sort(timePoints.begin(), timePoints.end());

        for(int i=1; i<n; i++) {
            int hourDiff = stoi(timePoints[i].substr(0,2)) - stoi(timePoints[i-1].substr(0,2));
            int minsDiff = stoi(timePoints[i].substr(3)) - stoi(timePoints[i-1].substr(3));
            int currTime = (hourDiff*60) + minsDiff;

            ans = min(ans, currTime);
        }

        int hourDiff = (24 - stoi(timePoints.back().substr(0,2))) + stoi(timePoints[0].substr(0,2));
        int minsDiff = (60 - stoi(timePoints.back().substr(3))) + stoi(timePoints[0].substr(3));
        int currTime = (hourDiff*60) - 60 + minsDiff;

        ans = min(ans, currTime);

        return ans;
    }
};
