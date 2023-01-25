//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int n=s.size();
        int ans=0;
        string temp="";
        for(int i=0; i<=n/2; i++){
            int f=0;
            for(int j=0; j<(i+1); j++){
                if(s[j]!=s[i+j+1]){
                    break;
                }
                f++;
            }
            if(f==i+1){
                ans=f;
            }
        }
        if(ans==0){
            return s.size();
        }
        return s.size()-ans+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
