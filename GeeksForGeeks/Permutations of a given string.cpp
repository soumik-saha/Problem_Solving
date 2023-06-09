//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
void f(int ind, int n,
	    string& s,
	    vector<string>& ans){
	        if(ind == n){
	            ans.push_back(s);
	            return;
	        }
	        for(int i=ind;i<n;i++){
	            swap(s[ind], s[i]);
	            f(ind+1, n, s, ans);
	            swap(s[ind], s[i]);
	        }
	    }
	    
		vector<string>find_permutation(string s){
		    sort(s.begin(), s.end());
		    vector<string> temp;
		    int n = s.size();
		    
		    f(0, n, s, temp);
		    
		    sort(temp.begin(), temp.end());
		    set<string> set_temp;
		    for(auto el:temp){
		        set_temp.insert(el);
		    }
		    
		    vector<string> ans;
		    for(auto el:set_temp){
		        ans.push_back(el);
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
