class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());

        long long decrement = 0;
        for(long long i=0; i<k; i++) {
            if(happiness[i]-decrement<=0) {
                break;
            }
            ans += (happiness[i]-(decrement++));
        }

        return ans;
    }
};
