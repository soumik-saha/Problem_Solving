class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans;
        for(int i=0; i<n; i++) {
            vector<char> v;
            for(int j=0; j<m; j++) {
                v.push_back(box[j][i]);
            }
            reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        for(int i=0; i<ans[0].size(); i++) {
            int ind = ans.size()-1;
            for(int j=ans.size()-1; j>=0; j--) {
                if(ans[j][i]=='#') {
                    swap(ans[j][i], ans[ind--][i]);
                }
                else if(ans[j][i]=='*') {
                    ind = j-1;
                }
            }
        }
        return ans;
    }
};
