class Solution {
    private static boolean check(int s, int e, char[][] board) {
        HashSet<Character> hs = new HashSet<>();
        for (int i = s; i < s + 3; i++) {
            for (int j = e; j < e + 3; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                if (hs.contains(ch)) return false;
                hs.add(ch);
            }
        }
        return true; 
    }

    public boolean isValidSudoku(char[][] board) {
        int R = board.length;
        int C = board[0].length;
        for (int i = 0; i < R; i++) {
            HashSet<Character> hs = new HashSet<>();
            for (int j = 0; j < C; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                if (hs.contains(ch)) return false;
                hs.add(ch);
            }
        }
        for (int j = 0; j < C; j++) {
            HashSet<Character> hs = new HashSet<>();
            for (int i = 0; i < R; i++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                if (hs.contains(ch)) return false;
                hs.add(ch);
            }
        }
        for (int i = 0; i < R; i += 3) {
            for (int j = 0; j < C; j += 3) {
                if (!check(i, j, board)) return false;
            }
        }

        return true;
    }
}
