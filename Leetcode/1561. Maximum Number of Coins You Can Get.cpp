class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size()/3;
        int ans = 0;
        sort(piles.begin(), piles.end(), greater<int>());

        for(int i=1; i<piles.size()-n; i=i+2) {
            ans += piles[i];
        }

        return ans;
    }
};
