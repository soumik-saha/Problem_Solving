//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
   public:
   vector<int> subarraySum(vector<int>arr, int n, long long s){
        if(s==0)
        return {-1};
        int start=0,end=0;
        long long windowSum=arr[0];
        while(end<n){
           if(windowSum<s){
               end++;
               windowSum+=arr[end];
           }
           else if(windowSum==s){
               return {start+1,end+1}; 
           }
           else if(windowSum>s){
               windowSum-=arr[start];
               start++;
           }
       }
       return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
