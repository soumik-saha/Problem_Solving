class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i=0; i<prices.size(); i++) {
            min1 = min(min1, prices[i]);
        }
        int cnt = 0;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i]==min1) {
                cnt++;
            }
            if((prices[i]>min1) || (prices[i]==min1 && cnt>1))
                min2 = min(min2, prices[i]);
        }
        cout<<min1<<" "<<min2;
        return (money - min1 - min2 < 0) ? money : money - min1 - min2;
    }
};
