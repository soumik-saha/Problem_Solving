//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool kPangram(string str, int k) {
        // code here
        vector<int> alpha(26, 0);
        for(char c:str) {
            if(c>='a' && c<='z')
            alpha[c-'a']+=1;
        }
        int extra = 0;
        int empty = 0;
        for(int it:alpha) {
            if(it==0)   empty++;
            else        extra += it-1;
        }
        return (empty<=extra && empty<=k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
