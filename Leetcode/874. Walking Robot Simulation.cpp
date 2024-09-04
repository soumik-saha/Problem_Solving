class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int x = 0, y = 0;
        unordered_map<int, unordered_set<int>> st;
        for(auto ob:obstacles) {
            st[ob[0]].insert(ob[1]);
        }
        int dir = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int ans = 0;
        for(int c:commands) {
            if(c==-1) {
                dir = (dir+1)%4;
            }
            else if(c==-2) {
                if(dir==0) {
                    dir = 3;
                }
                else {
                    dir--;
                }
            }
            else {
                for(int i=0; i<c; i++) {
                    int newx = x+dx[dir];
                    int newy = y+dy[dir];
                    if(st.find(newx)!=st.end() && st[newx].find(newy)!=st[newx].end()) {
                        break;
                    }
                    x = newx;
                    y = newy;
                }
            }
            ans = max(ans, (x*x+y*y));
        }
        return ans;
    }
};
