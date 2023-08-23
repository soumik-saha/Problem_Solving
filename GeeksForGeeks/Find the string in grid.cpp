//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        // Code here
        vector<vector<int>> ans;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dirs={{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,0},{1,1},{0,1}};
           
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(grid[i][j]==word[0] && isPossible(grid,word,i,j,dirs)){
                       ans.push_back({i,j});
                   }
               }
           }
           return ans;
    }
    
    bool isPossible(vector<vector<char>>grid, string word,int i,int j,vector<vector<int>> dirs){
        int n=grid.size();
        int m=grid[0].size();
        
        for(auto dir:dirs){
            int newi=i;
            int newj=j;
            int c=0;
            
            while(newi>=0 && newj>=0 && newi<n && newj<m && c<word.length() && grid[newi][newj]==word[c]){
                newi=newi+dir[0];
                newj=newj+dir[1];
                c++;
            }
            if(c==word.length()){
                return true;
            }
                
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
