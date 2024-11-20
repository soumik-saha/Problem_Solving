class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> count(3, 0);
        for(int i=0; i<n; i++) {
            count[s[i]-'a']++;
        }
        for(int i=0; i<3; i++) {
            if(count[i]<k)  return -1;
        }
        vector<int> window(3, 0);
        int maxWindow = 0;
        for(int l=0, r=0; r<n; r++) {
            window[s[r]-'a']++;
            while(l<=r && (count[0]-window[0]<k || count[1]-window[1]<k || count[2]-window[2]<k)) {
                window[s[l++]-'a']--;
            }
            cout<<l<<" "<<r<<endl;
            maxWindow = max(maxWindow, r-l+1);
        }
        return n-maxWindow;
    }
};
