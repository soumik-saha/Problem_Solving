//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int gap = 1;
        for(int i=0; i<n; i++) {
            int x = i+gap;
            if(x<n) {
                if(arr[i]<arr[x]) {
                    return false;
                }
            }
            if(x+1<n) {
                if(arr[i]<arr[x+1]) {
                    return false;
                }
            }
            gap++;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
