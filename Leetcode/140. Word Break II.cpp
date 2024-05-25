class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memoization;
        return dfs(s, wordSet, memoization);
    }

private:
    vector<string> dfs(const string& remainingStr,
                       const unordered_set<string>& wordSet,
                       unordered_map<string, vector<string>>& memoization) {

        if (memoization.count(remainingStr)) return memoization[remainingStr];

        if (remainingStr.empty()) return {""};
        vector<string> results;
        for (int i = 1; i <= remainingStr.length(); ++i) {
            string currentWord = remainingStr.substr(0, i);
            if (wordSet.count(currentWord)) {
                for (const string& nextWord :
                     dfs(remainingStr.substr(i), wordSet, memoization)) {
                    results.push_back(currentWord +
                                      (nextWord.empty() ? "" : " ") + nextWord);
                }
            }
        }
        memoization[remainingStr] = results;
        return results;
    }
};
