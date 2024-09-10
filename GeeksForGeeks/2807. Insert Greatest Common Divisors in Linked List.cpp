//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
     vis[node]=1;
     
     for(auto child: adj[node]){
         if(vis[child]==0){
             dfs(child,adj,vis);
         }
     }
    }
    
    int isCircle(vector<string> s)
    {
        int n = s.size();
        vector<int> adj[26];
        vector<int> in(26,0), out(26,0);
        
        for(int i=0;i<n;i++){
            int ch1=s[i][0]-'a';
            int ch2=s[i].back()-'a';
            
            adj[ch1].push_back(ch2);
            in[ch2]++;
            out[ch1]++;
        }
        
        vector<int> vis(26,0); 
        int src=0;
        
        
        for(int i=0;i<26;i++){
            if(in[i]!=out[i]){
                return 0;
            }
        }
        for(int i=0;i<26;i++){
            if(out[i]!=0){
                src=i;
                break;
            }
        }
        
        dfs(src,adj,vis);
        
        for(int i=0;i<26;i++){
            if(vis[i]==0 && out[i]){
                return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
