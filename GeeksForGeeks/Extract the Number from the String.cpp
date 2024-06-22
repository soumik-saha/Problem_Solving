//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        // code here
        long long ans = -1;
        for(int i=0; i<sentence.size(); i++) {
            string num = "";
            while(i<sentence.size() && sentence[i]>='0' && sentence[i]<='9') {
                num += sentence[i++];
            }
            bool hasNine = false;
            for(int j=0; j<num.size(); j++) {
                if(num[j]=='9') {
                    hasNine = true;
                    break;
                }
            }
            if(num.size()!=0 && !hasNine)
                ans = max(ans, stoll(num));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
