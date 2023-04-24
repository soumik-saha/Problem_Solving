class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        while(n!=0 && n!=1) {
            sort(stones.begin(), stones.end());
            int y = stones[n-1], x = stones[n-2];
            if(x==y){
                stones.pop_back();
                stones.pop_back();
            }
            else{
                int val = y-x;
                stones.pop_back();
                stones.pop_back();
                stones.push_back(val);
            }
            n=stones.size();
        }
        if(n==0)
            return 0;
        return stones[0];
    }
};
