class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Integer[][] dp = new Integer[n][m]; 
        return dfs(grid, 0, 0, n, m, dp);
    }

    private int dfs(int[][] grid, int r, int c, int n, int m, Integer[][] dp) {
        if (r >= n || c >= m) return Integer.MAX_VALUE;  
        if (r == n - 1 && c == m - 1) return grid[r][c];  
        if (dp[r][c] != null) return dp[r][c];
        int right = dfs(grid, r, c + 1, n, m, dp);
        int down = dfs(grid, r + 1, c, n, m, dp);
        dp[r][c] = grid[r][c] + Math.min(right, down);
        return dp[r][c];
    }
}
