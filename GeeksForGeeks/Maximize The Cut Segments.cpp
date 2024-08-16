//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    bool ispossible = false;
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        
        for(int i=1; i<=n; i++) {
            
            if(i-x>=0 && dp[i-x]!=-1) {
                dp[i] = max({dp[i], dp[i-x]+1});
            }
            
            if(i-y>=0 && dp[i-y]!=-1) {
                dp[i] = max({dp[i], dp[i-y]+1});
            }
            
            
            if(i-z>=0 && dp[i-z]!=-1) {
                dp[i] = max({dp[i], dp[i-z]+1});
            }
        }
        
        return (dp[n]!=-1) ? dp[n] : 0;
    }
    int solve(int i, int x, int y, int z, vector<int>& dp) {
        if(i==0) {
            ispossible = true;
            return 0;
        }
        
        if(i<0) {
            return -1;
        }
        
        if(dp[i]!=-1)   return dp[i];
        
        int segX = solve(i-x, x, y, z, dp);
        int segY = solve(i-y, x, y, z, dp);
        int segZ = solve(i-z, x, y, z, dp);
        
        if(segX==segY && segY==segZ && segX==-1) {
            dp[i] = -1;
        }
        else {
            dp[i] = max({segX, segY, segZ});
            if(dp[i]!=-1) {
                dp[i]++;
            }
        }
        
        return dp[i];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
