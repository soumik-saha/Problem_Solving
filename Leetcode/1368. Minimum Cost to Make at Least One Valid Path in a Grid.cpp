class Solution {
    vector<vector<int>> dir = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
    int m, n;

    bool isValid(int r, int c) {
        return r>=0 && c>=0 && r<m && c<n;
    }

public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<vector<int>> q;
        q.push({0,0,0});
        vector<vector<int>> minimumCost(m, vector<int>(n, INT_MAX));
        minimumCost[0][0] = 0;
        
        while(!q.empty()) {
            auto info = q.front();
            q.pop();
            int currCost = info[0];
            int r = info[1];
            int c = info[2];
            int cellVal = grid[r][c];
            int newR = r+dir[cellVal][0];
            int newC = c+dir[cellVal][1];
            int newCost = currCost;

            if(isValid(newR, newC) && minimumCost[newR][newC] > newCost) {
                minimumCost[newR][newC] = newCost;
                q.push({newCost, newR, newC});
            }

            for(int k=1; k<5; k++) {
                if(k!=cellVal) {
                    newR = r+dir[k][0];
                    newC = c+dir[k][1];
                    newCost = 1+currCost;
                    if(isValid(newR, newC) && minimumCost[newR][newC]>newCost) {
                        minimumCost[newR][newC] = newCost;
                        q.push({newCost, newR, newC});
                    }
                }
            }
        }

        return minimumCost[m-1][n-1];
    }
};
