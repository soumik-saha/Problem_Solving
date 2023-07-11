//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		vector<vector<bool>> seen(n, vector<bool>(m, false));
 		int dr[] = {0,1,0,-1};
 		int dc[] = {1,0,-1,0};
 		int x=0, y=0, dir=0;
 		
 		for(int i=0; i<m*n; i++) {
 		    if(i==k-1)    
 		        return a[x][y];
 		    
 		    seen[x][y]=true;
 		    int newX = x + dr[dir];
 		    int newY = y + dc[dir];
 		    
 		    if(newX>=0 && newX<n && newY>=0 && newY<m && !seen[newX][newY]) {
 		        x = newX;
 		        y = newY;
 		    }
 		    else {
 		        dir = (dir+1) % 4;
 		        x += dr[dir];
 		        y += dc[dir];
 		    }
 		}
 		
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
