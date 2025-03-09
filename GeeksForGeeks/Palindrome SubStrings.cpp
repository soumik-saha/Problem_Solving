//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.size();
        int count = 0;
        
        for(int i=0; i<n; i++) {
            checkPalindrome(i, i, s, count);
            checkPalindrome(i, i+1, s, count);
        }
        
        return count;
    }
    void checkPalindrome(int l, int r, string& s, int &count) {
        
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            if(l!=r)    count++;
            l--;
            r++;
        }
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
