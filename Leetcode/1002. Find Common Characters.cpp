class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> current(26, 0), common(26, 0);

        for (char c : words[0]) {
            common[c - 'a']++;
        }

        for (int i = 1; i < n; i++) {
            fill(current.begin(), current.end(), 0);

            for (char c : words[i]) {
                current[c - 'a']++;
            }

            for (int letter = 0; letter < 26; letter++) {
                common[letter] = min(common[letter], current[letter]);
            }
        }

        vector<string> result;

        for (int letter = 0; letter < 26; letter++) {
            for (int x = 0; x < common[letter]; x++) {
                result.push_back(string(1, letter + 'a'));
            }
        }

        return result;
    }
};
