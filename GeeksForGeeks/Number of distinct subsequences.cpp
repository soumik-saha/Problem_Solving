//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size(), MOD = 1e9+7;
	    vector<int> dp(n+1), last(26, -1);
	    dp[0]=1;
	    
	    for(int i=1; i<=n; i++) {
	        if(last[s[i-1]-'a']==-1) {
	            dp[i] = (dp[i-1] * 2);
	            last[s[i-1]-'a'] = i-1;
	        }
	        else {
	            dp[i] = (dp[i-1] * 2 - dp[last[s[i-1]-'a']]);
	            if(dp[i]<0) {
	                dp[i] += MOD;
	            }
	            last[s[i-1]-'a'] = i-1;
	        }
	        dp[i] %= MOD;
	    }
	    
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
