class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int last = meetings.front()[1];
        int count = last-meetings.front()[0]+1;

        for(int i=1; i<n; i++) {
            if(last>=meetings[i][1]) continue;
            cout<<meetings[i][0]<<meetings[i][1]<<endl;
            if(last<meetings[i][0])  count += meetings[i][1]-meetings[i][0]+1;
            else count += meetings[i][1]-last;
            last = meetings[i][1];
        }

        return days-count;
    }
};
