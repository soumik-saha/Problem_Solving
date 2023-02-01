//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[])

    {

        vector<pair<long long int,pair<long long int,long long int>> > dp(n);

        

        dp[0].first=r[0];

        dp[0].second={g[0],b[0]};

        

        for(int i=1;i<n;i++)

        {

            dp[i].first=min(dp[i-1].second.second,dp[i-1].second.first)+r[i];

            dp[i].second.first=min(dp[i-1].first,dp[i-1].second.second)+g[i];

            dp[i].second.second=min(dp[i-1].first,dp[i-1].second.first)+b[i];

        }

        return min(dp[n-1].first,min(dp[n-1].second.second,dp[n-1].second.first));

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
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
