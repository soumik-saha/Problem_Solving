class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
        for(int i=low; i<=high; i++){
            if(isOdd(i)){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
    int isOdd(int x){
        if(x%2!=0)
            return true;
        return false;
    }
};
