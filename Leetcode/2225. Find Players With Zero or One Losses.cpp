class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, pair<int, int>> stat;
        for(int i=0; i<matches.size(); i++) {
            stat[matches[i][0]].first++;
            stat[matches[i][1]].second++;
        }
        vector<int> win, lose;
        for(auto it : stat) {
            int player = it.first;
            int wincase = it.second.first;
            int losecase = it.second.second;
            if(losecase==0) {
                win.push_back(player);
            }
            if(losecase==1) {
                lose.push_back(player);
            }
        }
        sort(win.begin(), win.end());
        sort(lose.begin(), lose.end());
        return {win, lose};
    }
};
