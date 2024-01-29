//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalCount(string str){
	    vector<vector<int>> dp(101, vector<int>(901, 0));
	    int n = str.size();     
	    
	    for(int i=0; i<=900; i++) 
	        dp[n][i] = 1;
	    
	    for(int i=n-1; i>=0; i--) {
	        int sum = 0;
	        
	        for(int ind=i; ind<n; ind++) {
	            sum += str[ind] - '0';
	            for(int prevSum=0; prevSum<=900; prevSum++) {
	                if(sum>=prevSum)
	                    dp[i][prevSum] += dp[ind+1][sum];
	            }
	        }
	    }
	    
	    return dp[0][0];
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
