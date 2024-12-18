//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n<k) return -1;
        
        int sum = 0, maxi = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        
        int low = maxi, high = sum, res = 0;
        
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(isValid(mid, arr, k)) {
                res = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        
        return res;
    }
    bool isValid(int mid, vector<int>& arr, int k) {
        int req = 1, sum = 0;
        
        for(int i=0; i<arr.size(); i++) {
            if(sum + arr[i]>mid) {
                req++;
                sum = arr[i];
            }
            else {
                sum += arr[i];
            }
        }
        
        return req<=k;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
