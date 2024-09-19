//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string> v;
        int start = 0;
        str.push_back('.');
        for(int i=0; i<str.size(); i++) {
            start = i;
            while(i<str.size() && str[i]!='.') {
                i++;
            }
            v.push_back(str.substr(start,i-start));
        }
        
        reverse(v.begin(), v.end());
        string ans = v[0];
        for(int i=1; i<v.size(); i++) {
            ans += "." + v[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
