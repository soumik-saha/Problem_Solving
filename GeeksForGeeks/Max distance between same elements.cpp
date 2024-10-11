//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n = arr.size(), ans = 0;
        unordered_map<int, pair<int, int>> mp;
        
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i])!=mp.end())
                mp[arr[i]] = {min(mp[arr[i]].first, i), max(mp[arr[i]].second, i)};
            else 
                mp[arr[i]] = {i, i};
            
            ans = max(ans, mp[arr[i]].second - mp[arr[i]].first);
        }
        
        for(auto it:mp) {
            auto e = it.first;
            auto c = it.second;
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
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
