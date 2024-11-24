class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long n = matrix.size();
        long long ans = 0;
        long long negCnt = 0;
        long long minVal = LLONG_MAX;
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < n; j++) {
                ans += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    negCnt++;
                }
                minVal = min(minVal, (long long)(abs(matrix[i][j])));
            }
        }
        if (negCnt % 2) {
            ans -= 2 * minVal;
        }
        return ans;
    }
};
