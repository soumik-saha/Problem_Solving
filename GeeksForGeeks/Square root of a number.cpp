//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        if(n==1) {
            return 1;
        }
        long long int left = 0, right = n/2;
        long long int last = -1;
        while(left<=right) {
            long long int mid = (left+right)/2;
            if(mid*mid==n) {
                return mid;
            }
            else if(mid*mid>n) {
                right = mid-1;
            }
            else {
                left = mid + 1;
                last = mid;
            }
        }
        return last;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
