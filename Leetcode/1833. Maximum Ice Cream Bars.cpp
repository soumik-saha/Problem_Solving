class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int icecream = 0;
        while(icecream<costs.size() && costs[icecream]<=coins){
            coins -= costs[icecream];
            icecream++;
        }
        return icecream;
    }
};
