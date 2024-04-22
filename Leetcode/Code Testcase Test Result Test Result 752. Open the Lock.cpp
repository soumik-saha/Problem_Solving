class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> nextSlot = {
            {'0', '1'}, {'1', '2'}, {'2', '3'}, {'3', '4'}, {'4', '5'},
            {'5', '6'}, {'6', '7'}, {'7', '8'}, {'8', '9'}, {'9', '0'},
        };
        unordered_map<char, char> prevSlot = {
            {'0', '9'}, {'1', '0'}, {'2', '1'}, {'3', '2'}, {'4', '3'},
            {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'},
        };

        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;
        int turns = 0;

        if (visited.find("0000") != visited.end()) {
            return -1;
        }

        q.push("0000");
        visited.insert("0000");

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string node = q.front();
                q.pop();

                if (node == target) {
                    return turns;
                }

                for (int k = 0; k < 4; k++) {
                    string newCombo = node;
                    newCombo[k] = nextSlot[newCombo[k]];

                    if (visited.find(newCombo) == visited.end()) {
                        q.push(newCombo);
                        visited.insert(newCombo);
                    }

                    newCombo = node;
                    newCombo[k] = prevSlot[newCombo[k]];

                    if (visited.find(newCombo) == visited.end()) {
                        q.push(newCombo);
                        visited.insert(newCombo);
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};
