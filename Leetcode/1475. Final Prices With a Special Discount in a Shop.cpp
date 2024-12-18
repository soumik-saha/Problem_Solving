class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && prices[stk.top()]>=prices[i]) {
                prices[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        // return answer array
        return prices;
    }
};

// 5 9 2 4 1 question
// stk -> 

// 3 7 1 3 1 ans

// Time Complexity : O(N)
// Space Complexity: O(N)
