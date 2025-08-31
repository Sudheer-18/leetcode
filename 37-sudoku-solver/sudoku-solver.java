class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    public static boolean solve(char[][] board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char ch='1'; ch<='9'; ch++) {
                        if(checkvalid(board,i,j,ch)) {
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
    public static boolean checkvalid(char[][] board, int r,int c,char ch) {
        for(int i=0; i<9; i++) {
            if(board[r][i] == ch || board[i][c] == ch) return false;  
        }
        r -= r%3;
        c -= c%3;
        for(int i=r; i<r+3; i++) {
            for(int j=c; j<c+3; j++) {
                if(board[i][j] == ch) return false;
            }
        }
        return true;
    }
}