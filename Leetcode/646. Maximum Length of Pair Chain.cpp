class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

        int curr = INT_MIN, ans = 0;

        for(auto pair : pairs) {
            if(pair[0] > curr) {
                ans++;
                curr = pair[1];
            }
        }

        return ans;
    }
};
