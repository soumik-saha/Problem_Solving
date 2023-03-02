class Solution {
public:
    int compress(vector<char>& chars) {
        int streak = 1;
        int index = 0;
        for(int i = 1; i < chars.size(); i++) {
            if(chars[i - 1] == chars[i]) {
                streak++;
            } else {
                chars[index++] = chars[i - 1];
                if(streak == 1) continue;
                string streakString = to_string(streak);
                for(char c : streakString) {
                    chars[index] = c;
                    index++;
                }
                streak = 1;
            
            }
        }
        chars[index++] = chars[chars.size() - 1];
        if(streak == 1) return index;
        string streakString = to_string(streak);
        for(char c : streakString) {
            chars[index++] = c;
        }
        return index;
    }
};
