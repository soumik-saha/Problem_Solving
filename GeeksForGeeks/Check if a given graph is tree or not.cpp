//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<int> vis(n, 0);
        vector<int> adjlist[n];
        for(auto it: adj) {
            int u = it[0], v = it[1];
            if(u==v)    return 0;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        if(cycle(0, adjlist, vis, -1))  return 0;
        for(int i=0; i<n; i++)
            if(vis[i]==0)
                return 0;
        return 1;
    }
    bool cycle(int node, vector<int> adj[], vector<int>& vis, int parent) {
        vis[node] = 1;
        for(auto it:adj[node]) {
            if(!vis[it]) {
                if(cycle(it, adj, vis, node))
                    return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
