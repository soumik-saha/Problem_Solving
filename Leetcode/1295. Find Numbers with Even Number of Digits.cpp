class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            bool isEvenDigits = evenDigits(nums[i]);
            if(isEvenDigits){
                cnt++;
            }
        }
        return cnt;
    }
    
    bool evenDigits(int n){
        int cnt = 0;
        while(n>0){
            n /= 10;
            cnt++;
        }
        if(cnt%2==0)
            return true;
        return false;
    }
};
