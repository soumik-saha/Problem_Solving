//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int help(int currLen, int &reqLen, int currNum,int &m){
        if(currNum>m) return 0;
        if(currLen == reqLen) return 1;
        int temp = currNum*2;
        int res = 0;
        for(int i=temp;i<=m;i++){
            res += help(currLen+1,reqLen,i,m);
        }
        return res;
    }
    
    int numberSequence(int m, int n){
        // code here
        int ans = 0;
        for(int i=0;i<m;i++){
            ans+=help(1,n,i+1,m);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
