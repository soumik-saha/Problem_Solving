class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                bool check = false;
                if(mat[i][j]==1) {
                    check = true;
                    for(int k=0; k<mat.size(); k++) {
                        if(i==k)
                            continue;
                        if(mat[k][j]==1)
                            check = false;
                    }
                    for(int k=0; k<mat[0].size(); k++) {
                        if(j==k)
                            continue;
                        if(mat[i][k]==1)
                            check = false;
                    }
                }
                if(check)
                    count++;
            }
        }
        return count;
    }
};
