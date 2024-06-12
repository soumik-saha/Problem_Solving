//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count = 0;
        while(n >= 1) {
            if(hasFour(n)) {
                count++;
            }
            n--;
        }
        return count;
    }
    bool hasFour(int n) {
        while(n>0) {
            if(n%10==4) {
                return true;
            }
            n /= 10;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends
