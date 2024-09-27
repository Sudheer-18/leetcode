class Solution {
public:
    bool is_valid(int s, int e, vector<vector<char>>& board) {
        map<char, int> mp;
        for (int i = s; i < s + 3; i++) {
            for (int j = e; j < e + 3; j++) {
                if (board[i][j] == '.') continue;
                if (mp.find(board[i][j]) != mp.end()) return false;
                else mp[board[i][j]]++;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(); 
        int m = board[0].size(); 
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp.clear();
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') continue;
                if (mp.find(board[i][j]) != mp.end()) return false;
                else mp[board[i][j]]++;
            }
        }
        for (int j = 0; j < m; j++) {
            mp.clear();
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.') continue;
                if (mp.find(board[i][j]) != mp.end()) return false;
                else mp[board[i][j]]++;
            }
        }
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < m; j += 3) {
                if (!is_valid(i, j, board)) return false;
            }
        }

        return true;
    }
};
