class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        int sz = tasks.size();
        unordered_map<char, int> mp;
        for(char c:tasks) {
            mp[c]++;
        }

        priority_queue<int> pq;
        for(auto it:mp) {
            pq.push(it.second);
        }
        
        while(!pq.empty()) {
            int cycle = n+1;
            vector<int> pending;
            int cnt = 0;
            while(cycle-- && !pq.empty()) {
                if(pq.top()>1) {
                    pending.push_back(pq.top()-1);
                }
                pq.pop();
                cnt++;
            }
            for(int x:pending)
                pq.push(x);
            ans+=(pq.empty() ? cnt : n+1);
        }

        return ans;
    }
};
