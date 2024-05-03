class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        for (int i = 0; i < version1.size(); i++) {
            string s;
            while (i < version1.size() && version1[i] != '.') {
                s += version1[i++];
            }
            v1.push_back(stoi(s));
        }

        for (int i = 0; i < version2.size(); i++) {
            string s;
            while (i < version2.size() && version2[i] != '.') {
                s += version2[i++];
            }
            v2.push_back(stoi(s));
        }

        if (v1 == v2)
            return 0;

        int i = 0, j = 0;
        for (; i < v1.size() && j < v2.size(); i++, j++) {
            if (v1[i] < v2[j]) {
                return -1;
            }
            else if(v1[i]>v2[j]) {
                return 1;
            }
        }

        int m1=0, m2=0;

        for(int i=0; i<v1.size(); i++) {
            if(v1[i]==0)  continue;
            m1 = (m1*10) + v1[i];
        }
        
        for(int i=0; i<v2.size(); i++) {
            if(v2[i]==0)  continue;
            m2 = (m2*10) + v2[i];
        }

        if(m1>m2) {
            return 1;
        }
        else if(m1<m2) {
            return -1;
        }
        else {
            return 0;
        }
    }
};
