class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int score = 0;
        vector<int> maxLeft(n, 0);
        maxLeft[0] = values[0];
        for(int i=1; i<n; i++) {
            int currRight = values[i]-i;
            score = max(score, maxLeft[i-1]+currRight);
            int currLeft = values[i]+i;
            maxLeft[i] = max(maxLeft[i-1], currLeft);
        }
        return score;
    }
};
