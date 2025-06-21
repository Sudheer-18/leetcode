class Solution {
    // private int mini = Integer.MAX_VALUE;
    private int DFS(int[][] arr, int n, int m, int i, int j, int[][] DP) {
        if(i == n -1 && j == m - 1) {
            return Math.max(1,1-arr[i][j]);
        }
        if( i>=n || j >= m) return Integer.MAX_VALUE;
        if(DP[i][j] != -1) return DP[i][j];
        int right = DFS(arr,n,m,i,j+1, DP);
        int down = DFS(arr,n,m,i+1,j,DP);
        int mini = Math.min(right, down) - arr[i][j];
        DP[i][j] = Math.max(1, mini);

        return DP[i][j];
    }

    public int calculateMinimumHP(int[][] dungeon) {
        int n = dungeon.length;
        int m = dungeon[0].length;
        // boolean[][] vis = new boolean[n][m];
        int[][] DP = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(DP[i], -1);
        }
        return DFS(dungeon, n, m, 0, 0, DP);
    }
}
