//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    long long int numoffbt(long long int arr[], int n){
        long long int mini = 1e9;
        long long int maxi = -1e9;
        
        int m[int(1e5+1)];
        memset(m, 0, sizeof(m));
        
        for ( int i = 0; i<n; i++ ){
            
            m[arr[i]] = 1;
            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);
            
        }
        long int mod = 1000000007;
        long int ans = 0;
        
        for ( int i = mini; i<=maxi; i++ ){
            
            if ( m[i] == 0 )
                continue;
            
            if ( m[i] != 1 )
                continue;
            
            for ( int j = mini; j*j<= i; j++ ){
                
                if ( i % j == 0 && m[i/j] != 0 && m[j] != 0 ){
                    
                    if ( i/j != j )
                        m[i] += 2*(m[i/j] * m[j]);
                        
                    else
                         m[i] += m[j]*m[j];
                         
                    m[i] %= mod;
                
                    
                }
                
            }
            
            ans += m[i];
            ans %= mod;
            
        }
            
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends
