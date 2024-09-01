class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        for(int i=0; i<original.size();) {
            vector<int> v;
            for(int j=0; j<n && i<original.size(); j++) {
                v.push_back(original[i++]);
            }
            ans.push_back(v);
        }

        bool allok = true;

        if(ans.size()!=m) {
            allok = false;
        }
        for(int i=0; i<ans.size(); i++) {
            if(ans[i].size()!=n) {
                allok=false;
            }
        }
        return (allok) ? ans : vector<vector<int>>();
    }
};
