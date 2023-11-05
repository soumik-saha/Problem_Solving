//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second>b.second || (a.second==b.second && a.first>b.first);
    }
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        vector<pair<int, int>> sorted(mp.begin(), mp.end());
        sort(sorted.begin(), sorted.end(), cmp);
        vector<int> res;
        int i=0;
        for(auto it : sorted) {
            if(i==k) 
                break;
            res.push_back(it.first);
            i++; 
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
