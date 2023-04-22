//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)v[i]={arr[i],i};
    
    sort(arr.begin(),arr.end());
    sort(v.begin(),v.end());
    
     vector<long long>pre(n);
     pre[0]=arr[0];
     for(int i=1;i<n;i++)pre[i]=pre[i-1]+arr[i];
     
     vector<long long>ans(n);

     for(int i=0;i<n;i++){
         int ind=lower_bound(arr.begin(),arr.end(),v[i].first)-arr.begin();
         if(ind>0){
             if(arr[ind-1]<arr[i]){
                 ans[v[i].second]=pre[ind-1];
             }
             else{
                 if(ind>=2)ans[v[i].second]=pre[ind-2];
             }
         }
     }
     return ans;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
