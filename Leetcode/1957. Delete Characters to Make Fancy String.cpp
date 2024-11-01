class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            int cnt = 0;
            bool flag = false;
            while(i<s.size() && s[i]==c) {
                i++;
                cnt++;
                flag = true;
            }
            for(int k=0; k<min(2, cnt); k++) {
                ans.push_back(c);
            }
            if(flag)    i--;
        }
        return ans;
    }
};
