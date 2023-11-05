class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()) {
            int maxi = INT_MIN;
            for(int i=0; i<arr.size(); i++) {
                maxi = max(maxi, arr[i]);
            }
            return maxi;
        }
        int i=1;
        unordered_map<int, int> mp;
        while(1) {
            arr[0] = max(arr[0], arr[i%arr.size()]);
            mp[arr[0]]++;
            if(mp[arr[0]]==k) {
                return arr[0];
            }
            i++;
        }
        return -1;
    }
};
