//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int zeroCnt = 0;
        int n = arr.size();
        int j=0, i=0;
        
        while(i<n && j<n) {
            if(arr[j]!=0) {
                arr[i] = arr[j];
                i++;
                j++;
            }
            else {
                zeroCnt++;
                j++;
            }
        }
        
        for(int i=n-1; i>=0 && zeroCnt>0; i--) {
            zeroCnt--;
            arr[i] = 0;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
