//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long res1 = 1, res2 = 1, result;
    	sort(arr, arr+n);
    	
    	// Case 1: Maximum product is the product of largest, second largest and third largest elements.
    	for(int i=n-1; i>=n-3; i--) {
    	    res1 *= arr[i];
    	}
    	
    	// Case 2: Maximum product is the product of largest, smallest and second smallest elements.
    	for(int i=0; i<=1; i++) {
    	    res2 *= arr[i];
    	}
    	res2 *= arr[n-1];
    	
    	result = max(res1, res2);
    	
    	return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
