class Solution {
    public void gameOfLife(int[][] board) {
        int n = board.length;
        int m = board[0].length;
        int[][] ans = new int[n][m]; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int once = 0, zero = 0;
                for (int indexi = -1; indexi < 2; indexi++) {  
                    for (int indexj = -1; indexj < 2; indexj++) { 
                        int x = indexi + i, y = indexj + j;
                        if ((indexi != 0 || indexj != 0) && x >= 0 && x < n && y >= 0 && y < m) {
                            if (board[x][y] == 1) once++;  
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
}
