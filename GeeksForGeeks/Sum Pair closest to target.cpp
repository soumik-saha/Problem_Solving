//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        if(n<2) return {};
        sort(arr.begin(), arr.end());
        int left = 0, right = n-1;
        vector<int> ans(2);
        ans[0] = arr[0];
        ans[1] = arr[n-1];
        int min_diff = INT_MAX;
        int max_abs_diff = INT_MIN;
        
        while(left<right) {
            int current_sum = arr[left] + arr[right];
            int diff = abs(target - current_sum);
            if(diff < min_diff || (diff == min_diff && abs(arr[right] - arr[left]) > max_abs_diff)) {
                ans[0] = arr[left];
                ans[1] = arr[right];
                min_diff = diff;
                max_abs_diff = abs(arr[right] - arr[left]);
            }
            if (current_sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
