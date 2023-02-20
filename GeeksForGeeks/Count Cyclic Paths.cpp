//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    #define mod (int)(1e9+7)
    int countPaths(int N){
        long long int origin = 0, vertex = 1;
        for(int i=2;i<=N;i++)
        {
            origin = 3 * (vertex%mod);
            if(i%2) vertex = (origin%mod) + 1;
            else    vertex = (origin%mod) - 1;
        }
        return origin%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
