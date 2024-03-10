//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    vector<int> alpha(200,0);
	    for(int i=0; i<str.size(); i++) {
	        alpha[str[i]-'A']++;
	    }
	    string res = "";
	    for(int i=0; i<str.size(); i++) {
	        if(alpha[str[i]-'A']!=0)  {
	            res.push_back(str[i]);
	            alpha[str[i]-'A'] = 0;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
