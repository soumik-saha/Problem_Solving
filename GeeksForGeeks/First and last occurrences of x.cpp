//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int left=0, right=n-1, mid, ptr, l, r;
        
        while(left <= right) {
            mid = (left + right) / 2;
            if(arr[mid] == x) {
                l = mid;
                r = mid;
                
                while(arr[l] == x) {
                    l--;
                }
                while(arr[r] == x) {
                    r++;
                }
                return {l+1, r-1};
            }
            else if(arr[mid] > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return {-1, -1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
