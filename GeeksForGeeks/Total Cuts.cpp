//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int>&a){
        
        if(n==1)return 0;
        vector<int>suf(n);
        suf[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)suf[i]=min(suf[i+1],a[i]);
        int cnt=0;
        int mx=0;
        for(int i=0;i<n-1;i++){
            mx=max(mx,a[i]);
            if((mx+suf[i+1])>=k)cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
