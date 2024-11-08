//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        int ans = 1;
        string temp = s1; 
        while(s1.size()<s2.size()) {
            ans++;
            s1 += temp;
        }
        if(s1==s2)  return ans;
        int len = s2.size();
        
        for(int i=len; i<s1.size(); i++) {
            if(s1.substr(i-len, len)==s2) {
                return ans;
            }
        }
        
        s1 += temp;
        ans++;
        for(int i=len; i<s1.size(); i++) {
            if(s1.substr(i-len, len)==s2) {
                return ans;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends
