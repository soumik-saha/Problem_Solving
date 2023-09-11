class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;

        vector<int> grp[groupSizes.size()+1];
        for(int i=0; i<groupSizes.size(); i++) {
            grp[groupSizes[i]].push_back(i);

            if(grp[groupSizes[i]].size()==groupSizes[i]) {
                ans.push_back(grp[groupSizes[i]]);
                grp[groupSizes[i]].clear();
            }
        }

        return ans;
    }
};
