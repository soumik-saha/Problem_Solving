class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n =arrays.size();
        int minSoFar = arrays.front().front();
        int maxSoFar = arrays.front().back();
        int ans = 0;

        for(auto arr:arrays) {
            if(arr==arrays[0])  continue;
            ans = max({ans, arr.back()-minSoFar, maxSoFar-arr.front()});
            cout<<arr.back()-minSoFar<< maxSoFar-arr.front()<<endl;
            minSoFar = min(minSoFar, arr.front());
            maxSoFar = max(maxSoFar, arr.back());
        }

        return ans;
    }
};
