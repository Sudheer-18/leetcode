class Solution {
public:
    bool recursion(vector<vector<char>>& arr, string str, int i, int j, int k, int cnt) {
        if (i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size()) return false;
        if (cnt == str.size()) return true;
        if (arr[i][j] != str[k]) return false;

        char temp = arr[i][j];
        arr[i][j] = ' '; 

        bool found = recursion(arr, str, i + 1, j, k + 1, cnt + 1) ||
                     recursion(arr, str, i, j + 1, k + 1, cnt + 1) ||
                     recursion(arr, str, i - 1, j, k + 1, cnt + 1) ||
                     recursion(arr, str, i, j - 1, k + 1, cnt + 1);

        arr[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        if(board.size()==1 and board[0].size()==1 and word.size()==1) {
            for(int i=0;i<rows;i++) {
                for(int j=0;j<cols;j++) {
                    if(word[i]==board[i][j]) return true;
                }
            }
        }
        if(board.size()==1 && word.size()>board[0].size()) return false;
            // return true;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (recursion(board, word, i, j, 0, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
