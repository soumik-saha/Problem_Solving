class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]=1;
        }
        int i=1, l=0, n=arr.size();
        while(1) {
            if(mp[i]==1) {
                i++;
                continue;
            }
            l++;
            if(l==k) {
                return i;
            }
            i++;
        }
        return -1;
    }
};
