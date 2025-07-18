class Solution {

    private void  dfs(char[][] board ,int i,int j,int n, int m, boolean[][] vis) {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || board[i][j] == '.') return ;

        vis[i][j] = true;
        board[i][j] = '.';
        dfs(board,i,j+1,n,m,vis);
        dfs(board,i+1,j,n,m,vis);
    } 

    public int countBattleships(char[][] board) {
        int n = board.length;
        int m = board[0].length;
        int ans = 0; 
        boolean[][] vis = new boolean[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'X') {
                    dfs(board,i,j,n,m,vis);
                    ans++;
                }
            }
        }

        return ans;
    }
}