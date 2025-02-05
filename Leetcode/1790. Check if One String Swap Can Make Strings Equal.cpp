class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m!=n)    return false;

        vector<int> idx;

        for(int i=0; i<m; i++) {
            if(s1[i]!=s2[i]){
                idx.push_back(i);
            }
            if(idx.size()>2)    return false;
        }
        
        if(idx.size()==2) {
            swap(s1[idx[0]], s1[idx[1]]);
            return s1==s2;
        }

        return idx.size()==0;
    }
};
