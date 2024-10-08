//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxEle = *max_element(arr.begin(), arr.end());
        if(count(arr.begin(), arr.end(), maxEle)>1) return 2*maxEle;
        int secondMaxEle = INT_MIN;
        for(int ele:arr) {
            if(ele!=maxEle) {
                secondMaxEle = max(secondMaxEle, ele);
            }
        }
        return maxEle+secondMaxEle;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends
