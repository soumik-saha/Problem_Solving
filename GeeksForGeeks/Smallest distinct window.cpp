//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_set<char> st(str.begin(), str.end());
        unordered_map<char, int> window;
        int ans = INT_MAX;
        for(int left=0, right=0; right<str.size(); right++) {
            window[str[right]]++;
            while(left<=right && window[str[left]]>1) {
                window[str[left]]--;
                left++;
            }
            
            if(window[str[left]]>0 && window.size()==st.size()) {
                ans = min(ans, right-left+1);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
