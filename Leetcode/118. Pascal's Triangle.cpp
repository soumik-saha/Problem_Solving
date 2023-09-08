class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});

        for(int i=1; i<numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for(int j=1; j<i; j++) {
                row.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            row.push_back(1);
            ans.push_back(row);
        }

        return ans;
    }
};
