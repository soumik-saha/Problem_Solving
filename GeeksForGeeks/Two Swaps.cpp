//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int n = arr.size();
        int cnt = 0, i = 0;
        
        while(i<n) {
            if(cnt>2) {
                break;
            }
            if(arr[i]==i+1) {
                i++;
            }
            else {
                cnt++;
                swap(arr[i], arr[arr[i]-1]);
            }
        }
        
        return cnt==2 || cnt==0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends
