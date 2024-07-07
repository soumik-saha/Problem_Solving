class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0;
        
        while(numBottles>=numExchange) {
            int x = (numBottles/numExchange) * numExchange;
            count += x;
            numBottles -= x; 
            numBottles += x / numExchange;
        }

        count += numBottles;

        return count;
    }
};
