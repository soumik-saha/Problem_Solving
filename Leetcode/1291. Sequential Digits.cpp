class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int low_size = 0, high_size = 0;
        int low_temp = low, high_temp = high;

        while(low_temp>0) {
            low_size++;
            low_temp /= 10;
        }
        while(high_temp>0) {
            high_size++;
            high_temp /= 10;
        }

        for(int size=low_size; size<=high_size; size++) {
            for(int start=1; start<=10-size; start++) {
                int sz = size;
                int t = 0;
                int x = start;
                while(sz--) {
                    t = t*10 + (x++);
                }
                if(t>=low && t<=high) {
                    ans.push_back(t);
                }
            }
        }

        return ans;
    }
};
