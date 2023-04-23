//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        int left =0, right=n-1;
        while(left<right){
            if(arr[left]>=arr[right]) arr[left]=arr[left]%arr[right];
            else if(arr[right]>=arr[left]) arr[right]=arr[right]%arr[left];
            
            if(arr[left]==0) left++;
            else if(arr[right]==0) right--;
        }
        return arr[left];
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
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends
