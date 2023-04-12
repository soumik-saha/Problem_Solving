//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        int cnt = 0;
        vector<int> larr, rarr;
        int x = n/2;
        for(int i=0; i<x; i++){
            larr.push_back(arr[i]);
            rarr.push_back(arr[i+x]);
        }
        sort(larr.begin(), larr.end());
        sort(rarr.begin(), rarr.end());
        int i=x-1, j=x-1;
        while(i>=0 && j>=0){
            if(larr[i]>=5*rarr[j]){
                cnt+=(j+1);
                i--;
            }
            else {
                j--;
            }
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
