class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(int num:nums) {
            switch(num) {
                case 0:
                    red++;
                    break;
                case 1:
                    white++;
                    break;
                case 2:
                    blue++;
                    break;
            }
        }

        int index = 0;
        while(red--) {
            nums[index++] = 0;
        } 
        while(white--) {
            nums[index++] = 1;
        }
        while(blue--) {
            nums[index++] = 2;
        }
    }
};
