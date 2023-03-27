//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int memoizedWay(int n, int k, int prevDiff = 1) {
        if(n<=0 || k==0)
            return 0;
        if(k==1)
            return 1;
        int cnt = 0;
        for(int i=prevDiff; i<=(n+1)/k; i++){
            if(n-i>=i)
                cnt += memoizedWay(n-i,k-1,i);
        }
        return cnt;
    }
    int countWaystoDivide(int N, int K) {
        int cnt = memoizedWay(N, K);
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends
