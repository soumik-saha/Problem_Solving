class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        for(int i=0; i<n; i++) {
            pq.push({static_cast<double>(arr[i])/arr[n-1], {i, n-1}});
        }

        while(--k) {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second - 1;

            if(j>i) {
                pq.push({static_cast<double>(arr[i])/arr[j], {i, j}});
            }
        }

        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};
