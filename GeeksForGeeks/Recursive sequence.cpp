//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long MOD = 1e9 + 7;
        long long ans = 0;
        long long i = 1, last = 1;
        for(int x=0; x<n; x++) {
            long long temp = i;
            long long mul = 1;
            while(temp--) {
                mul = (mul*(last++)) % MOD;
            }
            ans = (ans + mul) % MOD;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
