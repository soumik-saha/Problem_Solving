class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixCount(n,0);
        prefixCount[0] = (isVowel(words[0][0]) && isVowel(words[0].back())) ? 1 : 0;
        for(int i=1; i<n; i++) {
            prefixCount[i] = prefixCount[i-1];
            if(isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefixCount[i] += 1;
            }
        }
        vector<int> ans;
        for(auto q:queries) {
            if(q[0]==0) 
                ans.push_back(prefixCount[q[1]]);
            else 
                ans.push_back(prefixCount[q[1]] - prefixCount[q[0]-1]);
        }
        return ans;
    }
    bool isVowel(char x) {
        return x=='a' || x=='e' || x=='i' || x=='o' || x=='u';
    }
};
