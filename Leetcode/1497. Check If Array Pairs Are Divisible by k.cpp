class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> seen(k+1, 0);

        for(int i=0; i<n; i++) {
            seen[((arr[i]%k)+k)%k]++;
        }

        for(int i=0; i<k; i++) {
            if(i==0) {
                if(seen[i]%2!=0)
                    return false;
                continue;
            }
            if(i==k-i) {
                continue;
            } 
            if(seen[i]!=seen[k-i]) {
                return false;
            }
        }

        return true;
    }
};
