//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string ds;
	    solve(n, ds, ans, 0, 0);
	    sort(ans.rbegin(), ans.rend());
	    return ans;
	}
	void solve(int n, string& ds, vector<string>& ans, int zero, int one) {
	    if(ds.size()==n) {
            ans.push_back(ds);
	        return;
	    }
	    ds.push_back('1');
	    solve(n, ds, ans, zero, one+1);
	    ds.pop_back();
	    if(zero*2<ds.size()) {
    	    ds.push_back('0');
    	    solve(n, ds, ans, zero+1, one);
    	    ds.pop_back();
	    }
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
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
