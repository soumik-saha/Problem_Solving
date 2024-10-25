class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder.front());

        for(int i=1; i<folder.size(); i++) {
            auto last = ans.back() + '/';

            if(folder[i].substr(0, last.size())!=last) {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
