//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long countSubarray(int N,vector<int> A,int M) {
        return solve(N, A, M) - solve(N, A, M+1);
    }
    long long solve(int N, vector<int> A, int M) {
        vector<int> mp(2*N+1, 0);
        long long cur = N, total = 0, cnt = 0;
        mp[cur]++;
        for(int i=0; i<N; i++) {
            int x = -1;
            if(A[i]>=M) {
                x = 1;
            }
            if(x==1){
                total += mp[cur];
            }
            else{
                total -= mp[cur+x];
            }
            cur += x;
            cnt += total;
            mp[cur]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends
