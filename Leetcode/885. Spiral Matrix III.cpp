class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;

        int step = 1;
        int r=rStart, c=cStart;
        int n = 0;
        while(n<rows*cols) {
            // right
            for(int i=0; i<step; i++) {
                if(r>=0 && r<rows && c>=0 && c<cols) {
                    ans.push_back({r,c});
                    n++;
                }
                c++;
            }

            // down
            for(int i=0; i<step; i++) {
                if(r>=0 && r<rows && c>=0 && c<cols) {
                    ans.push_back({r,c});
                    n++;
                }
                r++;
            }
            step++;

            // left
            for(int i=0; i<step; i++) {
                if(r>=0 && r<rows && c>=0 && c<cols) {
                    ans.push_back({r,c});
                    n++;
                }
                c--;
            }

            // up
            for(int i=0; i<step; i++) {
                if(r>=0 && r<rows && c>=0 && c<cols) {
                    ans.push_back({r,c});
                    n++;
                }
                r--;
            }
            step++;
        }

        return ans;
    }
};
