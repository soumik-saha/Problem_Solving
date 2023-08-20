//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int l=0, r=n-1; 
	    int index = 0;
	    while(l<=r) {
	        int mid = (l+r)/2;
	        if(arr[mid]==x){
                index = mid;
                break;
	        }
	        else if(arr[mid]>x) {
	            r = mid-1;
	        }
	        else {
	            l = mid+1;
	        }
	    }
	    int start=index, end=index;
	    if(index==0 && arr[index]!=x)
	        return 0;
	    while(arr[start]==x) {
	        start--;
	    }
	    while(arr[end]==x) {
	        end++;
	    }
	    start++;
	    end--;
	    return end-start+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
