class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> chonk(bank.size(), 0);
        for (int i = 0; i < bank.size(); i++) {
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1')
                    chonk[i]++;
            }
        }
        int ans = 0, last = 1;
        bool firsttime = true;
        for (int i = 0; i < chonk.size(); i++) {
            if (chonk[i] == 0)
                continue;
            if (firsttime) {
                firsttime = false;
                last = chonk[i];
                continue;
            }
            ans += last * chonk[i];
            last = chonk[i];
        }
        return ans;
    }
};
