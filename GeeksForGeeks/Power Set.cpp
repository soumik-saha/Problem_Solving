//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string> res;
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string ds;
		    solve(0, s, ds);
		    sort(res.begin(), res.end());
		    return res;
		}
		void solve(int i, string s, string& ds) {
		    if(i>=s.size()) {
		        res.push_back(ds);
		        return;
		    }
		    
		    if(!ds.empty())
		        res.push_back(ds);
		        
		    for(int ind=i; ind<s.size(); ind++) {
		        ds.push_back(s[ind]);
		        solve(ind+1, s, ds);
		        ds.pop_back();
		    }
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
