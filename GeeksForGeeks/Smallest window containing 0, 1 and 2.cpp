//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int ans = INT_MAX;
        int left = 0, right = 0;
        int count[3] = {0};
        
        while(right<S.size()) {
            count[S[right]-'0']++;
            right++;
            
            while(count[0]>0 && count[1]>0 && count[2]>0) {
                ans = min(ans, right-left);
                count[S[left]-'0']--;
                left++;
            }
        }
        
        return ans==INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
