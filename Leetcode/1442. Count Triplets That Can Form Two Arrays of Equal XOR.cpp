class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int a = arr[0], b = arr[1];
        int count = 0;
        for(int i=0; i<n; i++) {
            a = arr[i];
            for(int j=i+1; j<n; j++) {
                a ^= arr[j];
                b = arr[j];
                for(int k=j; k<n; k++) {
                    b ^= arr[k];
                    count += (a==b) ? 1 : 0;
                }
            }
        }
        return count;
    }
};
