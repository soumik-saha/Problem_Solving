class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double sum = 0;
        int start = -1;
        for(int i=0; i<n; i++) {
            start = max(customers[i][0], start);
            sum += start + customers[i][1] - customers[i][0];
            start = start + customers[i][1];
        }
        double ans = sum / n;
        return ans;
    }
};
