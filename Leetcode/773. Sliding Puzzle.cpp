class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string curr = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                curr.push_back(board[i][j] + '0');
            }
        }
        unordered_set<string> vis;
        vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5},
                                    {0, 4}, {1, 3, 5}, {2, 4}};

        queue<string> q;
        q.push(curr);
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto fr = q.front();
                q.pop();
                if (fr == target) {
                    return ans;
                }
                int zero = fr.find('0');
                for (int dir : dirs[zero]) {
                    string nxt = swapping(fr, zero, dir);
                    if (vis.find(nxt) != vis.end()) {
                        continue;
                    }
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
            ans++;
        }
        return -1;
    }
    string swapping(string s, int i, int j) {
        swap(s[i], s[j]);
        return s;
    }
};
