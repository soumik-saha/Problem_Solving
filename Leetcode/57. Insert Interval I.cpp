class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            int start = intervals[i][0];
            int end = intervals[i][1];

            while(i+1<n) {
                if(intervals[i+1][0]<=end) {
                    end = max(end, intervals[i+1][1]);
                    i++;
                }
                else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};
