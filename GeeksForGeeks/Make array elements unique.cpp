//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(),arr.end());
        int maxi = arr[0];
        long long int ans = 0;
        for(int i=1;i<N;++i){
            if(arr[i]>maxi){
                maxi = arr[i];
                continue;
            }
            int pre = arr[i];
            int ele = maxi+1;
            ans = ans + ele - pre;
            maxi = max(maxi,ele);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends
