//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        int ans = 0;
        vector<int> v(26, 0);
        for(int l=0, r=0; r<n; r++) {
            v[s[r]-'a']++;
            while(v[s[r]-'a']>1) {
                v[s[l]-'a']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
