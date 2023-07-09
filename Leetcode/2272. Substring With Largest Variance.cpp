class Solution {
public:
    int largestVariance(string s) {
        int result = 0;
        for (char highFreqChar = 'a'; highFreqChar <= 'z'; ++highFreqChar) {
            for (char lowFreqChar = 'a'; lowFreqChar <= 'z'; ++lowFreqChar) {
                if (highFreqChar == lowFreqChar) continue;
                
                int highFreq = 0;
                int lowFreq = 0;
                bool lowFreqAbandoned = false;
                
                for (const char& ch : s) {
                    if (ch == highFreqChar) ++highFreq;
                    if (ch == lowFreqChar) ++lowFreq;
                    
                    if (lowFreq > 0) {
                        result = max(result, highFreq - lowFreq);
                    } else {
                        if (lowFreqAbandoned) {
                            result = max(result, highFreq - 1);
                        }
                    } 
                    
                    if (lowFreq > highFreq) {
                        lowFreq = 0;
                        highFreq = 0;
                        lowFreqAbandoned = true;
                    }
                }
            }
        }
        return result;
    }
};
