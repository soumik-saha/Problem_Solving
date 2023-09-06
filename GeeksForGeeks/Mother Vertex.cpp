//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void DFS(int i, vector<int>adj[], vector<bool>& visited) {
        visited[i] = true;
        
        for(auto v :  adj[i]) {
            if(!visited[v]) {
                DFS(v, adj, visited);
            }
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> visited(V, false);
	    int motherVertex = 0;
	    
	    for(int i=0; i<V; i++) {
	        if(!visited[i]) {
	            DFS(i, adj, visited);
	            motherVertex = i;
	        }
	    }
	    
	    fill(visited.begin(), visited.end(), false);
	    DFS(motherVertex, adj, visited);
	    
	    for(auto it : visited) {
	        if(it==false) {
	            return -1;
	        }
	    }
	    return motherVertex;;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
