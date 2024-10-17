class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string s = to_string(num);
        int n = s.size();
        vector<pair<char,int>> suffixMax(n);
        suffixMax[n-1] = make_pair(s[n-1],n-1);
        for(int i=n-2; i>=0; i--) {
            if(suffixMax[i+1].first>=s[i])
                suffixMax[i] = suffixMax[i+1];
            else
                suffixMax[i] = make_pair(s[i],i);
        }
        string res = s;
        for(int i=0; i<n; i++) {
            string temp = s;
            swap(s[suffixMax[i].second], s[i]);
            ans = max(stoi(s), ans);
            s = temp;
        }
        return ans;
    }
};
