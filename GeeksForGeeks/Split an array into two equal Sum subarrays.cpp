//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        if(arr.size()==1)   return false;
        int l=1, r=arr.size()-2;
        int lsum = arr[0], rsum = arr[r+1];
        
        while(l<=r) {
            if(lsum>=rsum) {
                rsum+=arr[r--];
            } else {
                lsum+=arr[l++];
            }
            
        }
        
        
        return lsum==rsum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends
