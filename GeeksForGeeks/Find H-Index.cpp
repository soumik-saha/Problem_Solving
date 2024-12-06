//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        int maxi = *max_element(citations.begin(), citations.end());
        vector<int> v(maxi+1, 0);
        
        for(int i=0; i<n; i++) {
            v[citations[i]]++;
        } 
        
        for(int i=maxi-1; i>=0; i--) {
            v[i] += v[i+1];
            if(v[i]>=i) {
                return i;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
