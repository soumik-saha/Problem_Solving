class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0; i<n; i++) {
            if(pq.empty()) {
                pq.push({intervals[i][1], intervals[i][0]});
            }
            else {
                if(pq.top()[0]<intervals[i][0]) {
                    auto ele = pq.top();
                    pq.pop();
                    ele[0] = intervals[i][1];
                    pq.push(ele);
                }
                else {
                    pq.push({intervals[i][1], intervals[i][0]});
                }
            }
        }
        return pq.size();
    }
};
