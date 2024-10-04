class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int score = skill.front()+skill.back();
        long long chemistry = skill.front()*skill.back();
        for(int i=1; i<n/2; i++) {
            if(skill[i]+skill[n-1-i]!=score) {
                return -1;
            }
            chemistry += (skill[i]*skill[n-1-i]);
        }
        return chemistry;
    }
};
