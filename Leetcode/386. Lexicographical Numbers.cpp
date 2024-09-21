class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=9; i++) {
            generate(i, n, ans);
        }
        return ans;
    }
    void generate(int i, int n, vector<int>& ans) {
        if(i>n) return;

        ans.push_back(i);

        for(int j=0; j<=9; j++) {
            int next = i*10 + j;
            if(next<=n) {
                generate(next, n, ans);
            }
            else {
                break;
            }
        }
    }
};
