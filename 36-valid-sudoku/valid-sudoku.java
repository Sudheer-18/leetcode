class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0; i<9; i++) {
            HashSet<Character> hs = new HashSet<>();
            for(int j=0; j<9; j++) {
                char ch = board[i][j];
                if(ch == '.') continue;
                if(hs.contains(ch)) return false;
                hs.add(ch);
            }
        }
        for(int i=0; i<9; i++) {
            HashSet<Character> hs = new HashSet<>();
            for(int j=0; j<9; j++) {
                char ch = board[j][i];
                if(ch == '.') continue;
                if(hs.contains(ch)) return false;
                hs.add(ch);
            }
        }
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                if(!check(board,i,j)) return false;
            }
        }
        return true;
    }
    public static boolean check(char[][] board, int r ,int c) {
        HashSet<Character> hs = new HashSet<>();
        for(int i=r; i<r+3; i++) {
            for(int j=c; j<c+3;j++) {
                char ch = board[i][j];
                if(ch == '.') continue;
                if(hs.contains(ch)) return false;
                hs.add(ch);
            }
        }
        return true;
    }
}