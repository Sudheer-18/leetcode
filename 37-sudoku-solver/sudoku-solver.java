class Solution {
    public static boolean validcell(char[][] board,int r ,int c,char ch) {
        for(int i=0; i <9; i++) {
            if(board[r][i] == ch || board[i][c] == ch || board[3*(r/3) + i/3][3*(c/3)+i%3] == ch) return false;
        }
        return true;
    }
    public static boolean solve(char[][] board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(validcell(board,i,j,ch)) {
                            board[i][j] = ch;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    public void solveSudoku(char[][] board) {
        solve(board);
    }
}