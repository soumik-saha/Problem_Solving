class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n  = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;

        for(int i=0; i<n; i++) {
            q.push(i);
        }

        vector<int> ans(n);
        int i = 0;
        while(!q.empty()) {
            int topDeckIdx = q.front();
            q.pop();
            ans[topDeckIdx] = deck[i++];
            topDeckIdx = q.front();
            q.pop();
            q.push(topDeckIdx);
        }

        return ans;
    }
};
