class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        queue<pair<char, int>> q1, q2;
        for(auto i=0; i<n; i++) {
            if(start[i]!='_') {
                q1.push({start[i], i});
            }
            if(target[i]!='_') {
                q2.push({target[i], i});
            }
        }

        if(q1.size()!=q2.size())    return false;

        while(!q1.empty() && !q2.empty()) {
            auto [val1, idx1] = q1.front();
            q1.pop();
            auto [val2, idx2] = q2.front();
            q2.pop();

            if(val1!=val2 || (val1=='L' && idx1<idx2) || (val2=='R' && idx1>idx2)) {
                return false;
            }
        }

        return true;
    }
};
