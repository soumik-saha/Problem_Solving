class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = INT_MAX;
        int k = 0;
        int b = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < a){
                a = prices[i];
            }
            b = prices[i] - a;
            if(k < b){
                k = b;
            }
        }
        return k;
    }
};
