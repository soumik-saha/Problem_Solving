//User function Template for C++

class Solution {
 public:
 
   void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation)
   {
       vis[node] = 1;
       tin[node] = low[node] = timer++;
       int child = 0;
       for(auto it : adj[node])
       {
           
           if(!vis[it])
           {
               child++;
               dfs(it, node, vis, tin, low, timer, adj, isArticulation);
               
               low[node] = min(low[node], low[it]);
               
               if(low[it] >= tin[node] && parent != -1)
               {
                   isArticulation[node] = 1;
               }
               
           }
           else if(it != parent)
           {
               low[node] = min(low[node], tin[it]);
           }
       }
       
       if(parent == -1 && child>1)
           isArticulation[node] = 1;
   }
 
   vector<int> articulationPoints(int n, vector<int>adj[]) {
       // Code here
       vector<int>ans;
       vector<int> tin(n,-1);
       vector<int> low(n,-1);
       vector<int> vis(n,0);
       vector<int> isArticulation(n,0);
       int timer = 0;
       for(int i=0;i<n;i++)
       {
           if(!vis[i])
           {
               dfs(i,-1,vis,tin,low,timer,adj,isArticulation);
           }
       }
       for(int i=0;i<n;i++)
       {
           if(isArticulation[i]==1) 
               ans.push_back(i);
       }
       if(ans.size()==0)
       {
           return {-1};
       }
       return ans;
   }
};
