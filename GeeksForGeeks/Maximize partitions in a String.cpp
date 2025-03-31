//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.size();
        vector<int> last(26, 0);
        
        for(int i=0; i<n; i++) {
            last[s[i]-'a'] = i;
        }
        
        int count = 0, maxInd = 0;
        
        for(int i=0; i<n; i++) {
            maxInd = max(last[s[i]-'a'], maxInd);
            if(maxInd==i) {
                maxInd = i+1;
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
