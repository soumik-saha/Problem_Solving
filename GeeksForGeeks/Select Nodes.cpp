//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<int>vis;

    int count=0;

    bool dfs(vector<int>adj[],int i){

        vis[i]=1;

        bool select = false;

        for(auto childs:adj[i]){

            if(!vis[childs] && !dfs(adj,childs))

            {

                select=true;

            }

        }

        if(select){

            count++;

        }

        return select;

    }

    int countVertex(int N, vector<vector<int>>edges){

        // code here

        vector<int>adj[N+1];

        vis = vector<int>(N+1,0);

        for(auto ele : edges){

            adj[ele[0]].push_back(ele[1]);

            adj[ele[1]].push_back(ele[0]);

        }

        dfs(adj,1);

        return count;

    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
