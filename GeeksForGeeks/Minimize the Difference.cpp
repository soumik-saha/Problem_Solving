//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        int maxSuffix[n + 1];
        int minSuffix[n + 1];
        maxSuffix[n] = -1e9;
        minSuffix[n] = 1e9;
        maxSuffix[n - 1] = arr[n - 1];
        minSuffix[n - 1] = arr[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            maxSuffix[i] = max(maxSuffix[i + 1], arr[i]);
            minSuffix[i] = min(minSuffix[i + 1], arr[i]);
        }
        
        int maxPrefix = arr[0];
        int minPrefix = arr[0];
        int minDiff = maxSuffix[k] - minSuffix[k];
        for(int i = 1; i < n; i++){
            if(i + k <= n){
                int maxi = max(maxSuffix[i + k], maxPrefix);
                int mini = min(minSuffix[i + k], minPrefix);
                minDiff = min(minDiff, maxi - mini);
            }
            maxPrefix = max(maxPrefix, arr[i]);
            minPrefix = min(minPrefix, arr[i]);
        }
        return minDiff;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
