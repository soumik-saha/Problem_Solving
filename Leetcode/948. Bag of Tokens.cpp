class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.empty())
            return 0;

        int score = 0;
        sort(tokens.rbegin(), tokens.rend());
        int n = tokens.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = tokens[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + tokens[i];
        }
        // If we don't need to Face-down
        int temp = power;
        for(int i=n-1; i>=0; i--) {
            if(temp>=tokens[i]) {
                score++;
                temp -= tokens[i];
            }
            else {
                break;
            }
        }
        if(score==0)
            return 0;
        // When we need to make Face-down
        int x = 0;
        for(int i=0; i<n; i++) {
            x--;
            temp = power + prefixSum[i];
            int res = x;
            for(int j=n-1; j>=i+1; j--) {
                if(temp>=tokens[j]) {
                    res++;
                    temp -= tokens[j];
                }
                else {
                    break;
                }
            }
            score = max(score, res);
        }
        return score;
    }
};
