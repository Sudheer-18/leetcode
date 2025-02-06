class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int once = 0, zero = 0;
                for (int x = -1; x < 2; x++) {
                    for (int y = -1; y < 2; y++) {
                        int indI = i + x, indJ = j + y;
                        if ((x != 0 || y != 0) && indI > -1 && indI < n && indJ > -1 && indJ < m) {
                            if (board[indI][indJ]) once++;
                            else zero++;
                        }
                    }
                }
                if (board[i][j] == 0 && once == 3) ans[i][j] = 1;
                if (board[i][j] == 1 && (once == 2 || once == 3)) ans[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = ans[i][j];
            }
        }
    }
};
