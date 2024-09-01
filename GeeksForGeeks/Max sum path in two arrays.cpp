//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), m = arr2.size();
        
        int maxSum = 0, currSum1 = 0, currSum2 = 0;
        int i = 0, j = 0;
        
        while(i<n && j<m) {
            if(arr1[i]<arr2[j]) {
                currSum1 += arr1[i++];
            }
            else if(arr1[i]>arr2[j]) {
                currSum2 += arr2[j++];
            }
            else {
                maxSum += max(currSum1, currSum2) + arr1[i];
                i++;
                j++;
                currSum1=currSum2=0;
            }
        }
        
        while(i<n)  currSum1 += arr1[i++];
        
        while(j<m)  currSum2 += arr2[j++];
        
        maxSum += max(currSum1, currSum2);
        
        return maxSum;
    }   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
