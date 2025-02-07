class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> color, ball;

        for(auto q:queries) {
            int x = q[0], y = q[1];
            
            // same ball diff color
            if(ball.find(x)!=ball.end()) {
                color[ball[x]]--;
                if(color[ball[x]]==0) {
                    color.erase(ball[x]);
                }
            }
            
            ball[x] = y;
            color[y]++;

            result.push_back(color.size());
        }

        return result;
    }
};
