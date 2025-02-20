//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> lpq;
        priority_queue<int> rpq;
        vector<double> ans;
        
        for(int ele:arr) {
            if(lpq.size()==rpq.size()) {
                rpq.push(ele);
                int val = rpq.top();
                rpq.pop();
                lpq.push(val);
                ans.push_back(lpq.top());
            }
            else {
                lpq.push(ele);
                int val = lpq.top();
                lpq.pop();
                rpq.push(val);
                ans.push_back((lpq.top()+rpq.top())/2.0);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
