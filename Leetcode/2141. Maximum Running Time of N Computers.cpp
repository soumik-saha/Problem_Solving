class Solution {
private:
    bool isPossibleToRun(int n, vector<int>& batteries, long long avgTime) {
        long long duration = 0;
        
        for(int ele : batteries) {
            if(ele < avgTime)   duration += ele;
            else                duration += avgTime;
        }

        return duration >= avgTime * n;
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int ele : batteries)   sum += ele;

        long long startTime = 0, endTime = sum, ans = 0;

        while(startTime <= endTime) {
            long long avgTime = (startTime + endTime) / 2;

            if(isPossibleToRun(n, batteries, avgTime)) {
                ans = avgTime;
                startTime =  avgTime + 1;
            }
            else {
                endTime = avgTime - 1;
            }
        }

        return ans;
    }
};
