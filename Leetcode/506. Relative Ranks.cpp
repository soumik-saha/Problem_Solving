class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> ranking = score;
        sort(score.rbegin(), score.rend());
        unordered_map<int, string> mp;
        int position = 1;

        for (int i = 0; i < score.size(); i++) {
            if (i == 0) {
                mp[score[i]] = "Gold Medal";
            }

            else if (i == 1) {
                mp[score[i]] = "Silver Medal";
            }

            else if (i == 2) {
                mp[score[i]] = "Bronze Medal";
            } 
            
            else {
                mp[score[i]] = to_string(position);
            }
            position++;
        }

        for (int i = 0; i < ranking.size(); i++) {
            ans.push_back(mp[ranking[i]]);
        }

        return ans;
    }
};
