class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1; 
        long long right = 1e14;
        
        while(left<right) {
            long long mid = left + (right-left)/2;
            if(isFeasible(ranks, cars, mid)) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
    bool isFeasible(vector<int>& ranks, int cars, long long mid) {
        long long total = 0;
        for(int rank:ranks) {
            long long maxCars = floor(sqrt(mid/rank));
            total += maxCars;
        }
        return total>=cars;
    }
};
