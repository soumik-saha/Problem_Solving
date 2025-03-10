class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k+1);
    }
    long long atLeastK(string word, int k) {
        int n = word.size();
        long long count = 0;
        long long consonants = 0;
        unordered_map<char, long long> freq;
        int start = 0;

        for(int l=0, r=0; r<n; r++) {
            char c = word[r];
            if(isVowel(c)) {
                freq[c]++;
            }
            else {
                consonants++;
            }

            while(consonants>=k && freq.size()==5) {
                count += n - r;
                char start = word[l];
                if(isVowel(start)) {
                    if(--freq[start]==0) {
                        freq.erase(start);
                    }
                }
                else {
                    consonants--;
                }
                l++;
            }
        }

        return count;
    }
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};
