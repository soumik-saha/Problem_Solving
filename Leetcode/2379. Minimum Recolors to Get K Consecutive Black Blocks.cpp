class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = blocks[0] == 'B';

        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + (blocks[i] == 'B');
        }

        int ans = k - prefixSum[k-1];

        for(int i=k; i<n; i++) {
            ans = min(ans, k - (prefixSum[i]-prefixSum[i-k]));
        }

        return ans;
    }
};
