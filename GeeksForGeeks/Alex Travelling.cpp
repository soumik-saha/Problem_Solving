// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<pair<int,int>> graph[n+5];
        for(auto x:flights){
            graph[x[0]].push_back({x[1],x[2]});
        }
        vector<int> cost(n+5,1e9);
        cost[k]=0;
        queue<int> q;
        q.push(k);
        while(q.size()){
            int src=q.front();
            q.pop();
            for(auto dest:graph[src]){
                if(cost[dest.first]>cost[src]+dest.second){
                    q.push(dest.first);
                    cost[dest.first]=cost[src]+dest.second;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,cost[i]);
        }
        return ans==1e9?-1:ans;
    }
};
