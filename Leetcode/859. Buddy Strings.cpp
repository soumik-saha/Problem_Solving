class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;

        if(s==goal) {
            unordered_map<char, int> mp;
            for(int i=0; i<s.size(); i++) {
                if(mp[s[i]]==1)
                    return true;
                    mp[s[i]]++;
            }
            return false;
        }

        int firstIndex=-1, secondIndex=-1;

        for(int i=0; i<s.size(); i++) {
            if(s[i]!=goal[i]) {
                if(firstIndex==-1)
                    firstIndex=i;
                else if(secondIndex==-1)
                    secondIndex=i;
                else
                    return false;
            }
        }
        if(secondIndex==-1)
            return false;
        
        return s[firstIndex] == goal[secondIndex] && s[secondIndex] == goal[firstIndex];
    }
};
