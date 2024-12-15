class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, vector<int>>> pq;
        
        for(int i=0; i<n; i++) {
            pq.push({((double)(classes[i][0]+1)/(classes[i][1]+1))-(double)classes[i][0]/classes[i][1], classes[i]});
        }

        while(!pq.empty() && extraStudents--) {
            auto ele = pq.top();
            pq.pop();
            ele.first = ((double)(ele.second[0]+2)/(ele.second[1]+2))-((double)(ele.second[0]+1)/(ele.second[1]+1));
            ele.second  = {ele.second[0]+1, ele.second[1]+1};
            pq.push(ele);
        }

        double ans = 0;
        while(!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            ans += (double)ele.second[0]/ele.second[1];
        }
        ans /= n;

        return ans;
    } 
};
