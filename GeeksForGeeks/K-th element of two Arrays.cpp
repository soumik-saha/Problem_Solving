//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int idx = 0;
        int l1 = 0, n = arr1.size();
        int l2 = 0, m = arr2.size();
        while(l1<n && l2<m) {
            idx++;
            if(arr1[l1]<=arr2[l2]) {
                if(idx==k) {
                    return arr1[l1];
                }
                l1++;
            } else {
                if(idx==k) {
                    return arr2[l2];
                }
                l2++;
            }
        }
        while(l1<n) {
            idx++;
            if(idx==k) {
                return arr1[l1];
            }
            l1++;
        }
        while(l2<m) {
            idx++;
            if(idx==k) {
                return arr2[l2];
            }
            l2++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends
