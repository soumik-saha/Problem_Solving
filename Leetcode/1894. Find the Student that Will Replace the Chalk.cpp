class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long n = chalk.size();
        for (long i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        long totalChalkNeeded = accumulate(chalk.begin(), chalk.end(), 0);
        k = k % totalChalkNeeded;
        for (long i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};
