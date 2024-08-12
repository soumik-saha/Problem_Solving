//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int m = arr1.size(), n = arr2.size();
        int xIdx = (m+n)/2, yIdx = xIdx+1;
        if(xIdx==0) {
            int ans = arr1[0] + arr2[0];
            return ans;
        }
        int id1 = 0, id2 = 0;
        int i;
        int ans = 0;
        int cazz = -1;
        for(i=0; i<=xIdx; i++) {
            if(i==xIdx || i==yIdx) {
                // cout<<cazz<<endl;
                ans += cazz;
                break;
            }
            if(id1<m && arr1[id1]<=arr2[id2]) {
                cazz = arr1[id1];
                id1++;
            } 
            else if(id2<n) {
                cazz = arr2[id2];
                id2++;
            }
        }
        
        // cout<<ans<<endl;
        
        ans += (arr1[id1]<=arr2[id2]) ? arr1[id1] : arr2[id2];
        
        return ans;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends
