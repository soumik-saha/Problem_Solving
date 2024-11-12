class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(), arr.end());
        int currEnd = -1;
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            if(arr[i][0]<currEnd) {
                return false;
            }
            currEnd = arr[i][1];
        }
        
        return true;
    }
};
