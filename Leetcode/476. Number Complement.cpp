class Solution {
public:
    int findComplement(int num) {
        string complement = "";
        while(num>0) {
            complement.push_back(((num%2)+'0'=='0') ? '1':'0');
            num/=2;
        }
        reverse(complement.begin(), complement.end());
        int ans = 0;
        int idx = 0;
        for(int i=complement.size()-1; i>=0; i--) {
            ans += (complement[i]-'0') * pow(2, (idx++));
        }
        return ans;
    }
};
