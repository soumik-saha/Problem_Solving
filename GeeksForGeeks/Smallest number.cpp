//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        int start = 1;
        for(int i=1; i<d; i++) {
            start *= 10;
        }
        
        int end = 9;
        for(int i=1; i<d; i++) {
            end = end*10 + 9;
        }
        
        while(start<=end) {
            if(digitSum(start)==s) {
                return to_string(start);
            }
            start++;
        }
        
        return "-1";
    }
    int digitSum(int n) {
        int sum = 0;
        while(n>0) {
            sum +=(n%10);
            n /= 10;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
