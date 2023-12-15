//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    const int MOD = 1e9 + 7;
		    vector<int> dp(n, 0);
		    for(int i=0; i<n; i++) {
		        if(i==0)
		            dp[i] = 1;
		        else if(i==1)
		            dp[i] = 2;
		        else
		            dp[i] = (dp[i-1] + dp[i-2])%MOD;
		    }
		    return dp[n-1];
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
