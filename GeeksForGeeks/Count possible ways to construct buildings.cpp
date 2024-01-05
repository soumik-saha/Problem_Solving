//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    const int MOD = 1e9 + 7;
	    vector<long long> dp(N+1);
	    
	    dp[0] = 1;
	    dp[1] = 2;
	    
	    for(int i=2; i<=N; i++) {
	        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	    }
	    
	    return (int)((dp[N]*dp[N])%MOD);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
