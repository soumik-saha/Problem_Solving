class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
        aheadNotBuy = aheadBuy = 0;
        for(int i=prices.size()-1; i>=0; i--) {
            curNotBuy = max(prices[i]-fee+aheadBuy, 0+aheadNotBuy);
            curBuy = max(-prices[i]+aheadNotBuy, 0+aheadBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};
