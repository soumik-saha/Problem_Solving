//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int ans = 0;
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<vector<int>> adj(n+1);
	    for(auto edge:edges) {
	        adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
	    }
	    
	    dfs(adj, 1, -1);
	    return ans;
	}
	int dfs(vector<vector<int>>& adj, int node, int parent) {
	    int cnt = 1;
	    
	    for(auto it:adj[node]) {
	        if(it!=parent) {
	            int subtree = dfs(adj, it, node);
	            
	            if(subtree%2==0) {
	                ans++;
	            }
	            else {
	                cnt++;
	            }
	        }
	    }
	    
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends
