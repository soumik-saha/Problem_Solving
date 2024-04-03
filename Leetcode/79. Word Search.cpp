class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (solve(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }

    bool solve(int i, int j, int idx, vector<vector<char>>& board, string& word) {
        if (idx == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '*'; // Marking visited

        bool found = solve(i + 1, j, idx + 1, board, word) ||
                     solve(i - 1, j, idx + 1, board, word) ||
                     solve(i, j + 1, idx + 1, board, word) ||
                     solve(i, j - 1, idx + 1, board, word);

        board[i][j] = temp; // Revert back the value

        return found;
    }
};
