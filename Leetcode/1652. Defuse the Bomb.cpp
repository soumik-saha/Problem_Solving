class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if(k==0) {
            return res;
        }
        for(int i=0; i<n; i++) {
            if(k>0) {
                int t = k;
                int ind = i+1;
                int sum = 0;
                while(t--) {
                    sum += code[ind%n];
                    ind++;
                }
                res[i] = sum;
            }
            else if(k<0) {
                int t = abs(k);
                int ind = i-1;
                int sum = 0;
                while(t--) {
                    if(ind<0) {
                        ind = n-1;
                    }
                    sum += code[ind];
                    ind--;
                }
                res[i] = sum;
            }
        }
        return res;
    }
};
