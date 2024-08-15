class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int dollar5Bills = 0;
        int dollar10Bills = 0;
        for (int bill : bills) {
            switch (bill) {
                case 5:
                    dollar5Bills++;
                    break;
                case 10:
                    if(dollar5Bills<=0)  return false;
                    dollar5Bills--;
                    dollar10Bills++;
                    break;
                default:
                    if(dollar10Bills>0 && dollar5Bills>0) {
                        dollar10Bills--;
                        dollar5Bills--;
                    } 
                    else if(dollar5Bills>=3) {
                        dollar5Bills -= 3;
                    }
                    else {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
};
