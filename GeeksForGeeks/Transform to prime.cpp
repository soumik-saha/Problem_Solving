//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        int sum = 0;
        for(int i=0; i<N; i++) {
            sum += arr[i];
        }
        
        int add = 0;
        while(true) {
            if(checkPrime(sum+add)==true) {
                return add;
            } else {
                add ++;
            }
        }
        return -1;
    }
    
    private:
    bool checkPrime(int n) {
        if(n <= 2) return true;
        
        for(int i=2; i<n; i++) {
            if(n%i==0)
                return false;
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
